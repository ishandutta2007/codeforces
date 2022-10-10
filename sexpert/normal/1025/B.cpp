#include <bits/stdc++.h>

using namespace std;

long long findPrime(long long n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(!(n%i)) return findPrime(i);
    }
    return n;
}

long long gcd(long long a, long long b)
{
    return a ? gcd(b%a, a) : b;
}

int main()
{
	int n;
	cin >> n;
	pair<long, long> pairs[150005];
	long long guys[150005];
	long long ans;
	for(int i = 0; i < n; i++)
	{
	    long long a, b, c;
	    cin >> a >> b;
	    pairs[i] = make_pair(a, b);
	    c = a * b;
	    guys[i] = c;
	}
	long long g = guys[0];
	for(int i = 1; i < n; i++) g = gcd(g, guys[i]);
	if(g == 1) ans = -1;
	else
	{
	    long long x = gcd(g, pairs[0].first);
	    if(x > 1) g = x;
	    else g = gcd(g, pairs[0].second);
	    ans = findPrime(g);
	}
	cout << ans << "\n";
}