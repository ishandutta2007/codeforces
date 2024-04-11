#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2000005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n, m;
int a[maxn], b[maxn];
int cnt[maxn], mxs[maxn];
int to(int a, int b)
{
	if(b >= a) return b - a;
	return n + b - a;
}
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		mxs[i] = n + 10;
	for(int i = 1; i <= m; i++)
		cin>>a[i]>>b[i], cnt[a[i]]++, 
		mxs[a[i]] = min(mxs[a[i]], to(a[i], b[i]));
	for(int i = 1; i <= n; i++)
		if(!cnt[i]) mxs[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		int mns = 0;
		for(int j = 1; j <= n; j++)
			mns = max(mns, n * (cnt[j] - 1) + to(i, j) + mxs[j]); 
	//		cout<<i<<" "<<j<<" "<<mns<<" "<<to(2, 1)<<" "<<mxs[1]<<endl;
		cout<<mns<<" ";
	}
	return 0;
}