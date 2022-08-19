#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
#define mod 998244353
int n, k;
int a[maxn];
int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a % b);
}
int main()
{
	cin>>n>>k;
	int ns = k;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		int r = gcd(a[i], k);
		ns = gcd(r, ns);
	}
	cout<<k / ns<<endl;
	for(int j = 0; j * ns < k; j++)
		cout<<j * ns<<" ";
	return 0;	
}