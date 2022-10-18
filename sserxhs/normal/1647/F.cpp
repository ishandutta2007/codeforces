#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5,inf=2e9;
int a[N],suf[N],pre[N],nd[N],n1[N],n2[N];
int n;
int solve()
{
	int x=max_element(a+1,a+n+1)-a,r=0,i,j;
	pre[1]=a[1];
	for (i=2;i<=n;i++) pre[i]=max(pre[i-1],a[i]);
	suf[n]=a[n];
	for (i=n-1;i;i--) suf[i]=max(suf[i+1],a[i]);
	vector<int> b;
	for (i=x;i<=n;i++) if (suf[i]!=a[i]) b.push_back(a[i]);
	reverse(all(b));
	if (!is_sorted(all(b))) return 0;
	int R=b.size()?b.back():0;
	//cerr<<R<<endl;
	int U=R,D=a[x];
	for (i=1;i<=n;i++) if (pre[i]==a[i]) nd[i]=nd[i-1],n1[i]=a[i],n2[i]=n2[i-1]; else
	{
		if (a[i]<nd[i-1]) break; else nd[i]=a[i],n1[i]=n1[i-1],n2[i]=a[i];
	}
	int L=i;
	//for (i=1;i<=n;i++) cerr<<nd[i]<<" \n"[i==n];
	//for (i=1;i<=n;i++) cerr<<n1[i]<<" \n"[i==n];
	//for (i=1;i<=n;i++) cerr<<n2[i]<<" \n"[i==n];
	for (i=x-1;i;i--)
	{
		//		dbg(i,U,D);
		if (a[i]>U)
		{
			if (i<L&&(pre[i]==a[i]&&n2[i]<D||pre[i]!=a[i]&&n1[i]<D))
			{
				++r;//dbg(i);
			}
		}
		if (a[i]>=U&&a[i]<=D)
		{
			if (i==1||a[i-1]<a[i]) D=a[i]; else U=a[i];
		}
		else if (a[i]>=U) U=a[i]; else if (a[i]<=D) D=a[i]; else return r;
	}
	return r;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int i;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	ans+=solve();//return 0;
	reverse(a+1,a+n+1);
	//for (i=1;i<=n;i++) cerr<<a[i]<<" \n"[i==n];
	//cerr<<ans<<endl;
	ans+=solve();
	cout<<ans<<endl;
}
/*
[5 8 12 34 7 24 48 31 17]
[5 8 12 34 48 31] [7 24 17]
[5 8 12 24 48 31 17] [34 7]

[5 8 12 34 48] [7 24 31 17]
*/