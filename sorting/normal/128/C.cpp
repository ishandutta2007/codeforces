#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
const long long N = 1007;

long long comb[N][N];

long long combination(long long n, long long k)
{
	//cout<<n <<" "<<k<<endl; 
	if(n==k)
		return 1;
	if(n== 1)
		return 1;
	if(k == 0)
		return 1;
	if(comb[n][k])
		return comb[n][k];

	comb[n][k] = combination(n-1, k) + combination(n-1, k-1);

	if(comb[n][k] >= mod)
		comb[n][k] -= mod;

	return comb[n][k];
} 

int main ()
{
	long long n, m, k;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m>>k;

	n -= 2*k;
	m -= 2*k;

	if(n <= 0 || m <= 0)
	{
		cout<<"0\n";
		return 0;
	}

	long long res = combination(n+2*k-1,2*k) * combination(m+2*k-1, 2*k);

	res %= mod;

	cout<<res<<"\n";

	return 0;
}