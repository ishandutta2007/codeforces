#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n;
ll a[maxn];
int b[maxn];
int cal(int m)
{
	m %= n;
	if(m == 0) return n;
	return m;
}
int main()
{
	scanf("%d", &n);
	int mxs = 0;
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]), 
		mxs = max(mxs, b[i]);
	if(mxs == 0)
	{
		cout<<"YES"<<endl;
		for(int i = 1; i <= n; i++)
			cout<<"1 ";
		return 0;
	}
	int fl = 0;
	for(int i = 1; i <= n; i++)
		if(b[i] == mxs && b[cal(i - 1)] != mxs)
		{
			int j = i;
			a[i] = mxs;
			while(j != cal(i + 1))
			{
				a[cal(j - 1)] = a[j] + b[cal(j - 1)];
				if(j == i) a[cal(j - 1)] += a[j];
				j = cal(j - 1);
			}
			cout<<"YES"<<endl;
			for(int j = 1; j <= n; j++)
				cout<<a[j]<<" ";
			return 0;
		}
	cout<<"NO"<<endl;
	return 0;
}