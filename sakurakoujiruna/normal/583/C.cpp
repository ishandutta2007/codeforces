#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int N = 511;
int a[N];

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios :: sync_with_stdio(false);

	int n;
	cin >> n;

	multiset <int> s;
	for(int i = 1; i <= n * n; i ++)
	{
		int x;
		cin >> x;
		s.insert(x);
	}

	for(int i = 1; i <= n; i ++)
	{
		a[i] = *s.rbegin();
		s.erase(s.find(a[i]));
		for(int j = 1; j < i; j ++)
		{
			s.erase(s.find(gcd(a[i], a[j])));
			s.erase(s.find(gcd(a[i], a[j])));
		}
	}

	for(int i = 1; i <= n; i ++)
		cout << a[i] << ' ';
	cout << '\n';

	return 0;
}