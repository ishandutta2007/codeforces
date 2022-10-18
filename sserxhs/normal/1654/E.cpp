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
const int N=1.2e6;
int a[N],CNT[N*40],*cnt=CNT+N*20,st[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,d,r=0;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (d=-200;d<=200;d++)
	{
		int tp=0;
		for (i=1;i<=n;i++) ++cnt[st[++tp]=a[i]-i*d];
		for (i=1;i<=tp;i++) r=max(r,cnt[st[i]]),cnt[st[i]]=0;
	}
	for (i=1;i<=n;i++)
	{
		int tp=0;
		for (j=i+1;j<=min(n,i+520);j++)
		{
			int D=(a[j]-a[i])/(j-i);
			if (D*(j-i)==(a[j]-a[i]))
			{
				++cnt[D];
				st[++tp]=D;
			}
		}
		for (j=1;j<=tp;j++) r=max(r,cnt[st[j]]+1),cnt[st[j]]=0;
	}
	cout<<n-r<<endl;
}