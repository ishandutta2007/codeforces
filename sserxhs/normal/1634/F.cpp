#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...); 1;
#endif
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const int N=3e5+10;
ui a[N],f[N],p,cnt;
void add(int x,ui y)
{
	cnt-=a[x]!=0;
	if ((a[x]+=y)>=p) a[x]-=p;
	cnt+=a[x]!=0;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i;
	cin>>n>>m>>p;
	f[1]=1%p;f[2]=1%p;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) cin>>cnt,a[i]=(a[i]+p-cnt)%p;n+=2;
	for (i=3;i<=n;i++) if ((f[i]=f[i-1]+f[i-2])>=p) f[i]-=p;
	for (i=n;i>1;i--) a[i]=(a[i]+p*2-a[i-1]-a[i-2])%p;cnt=0;
	for (i=1;i<=n;i++) cnt+=a[i]!=0;
	while (m--)
	{
		char c;
		int l,r;
		cin>>c>>l>>r;
		if (c=='A') add(l,1),add(r+1,p-f[r-l+2]),add(r+2,p-f[r-l+1]);
		else add(l,p-1),add(r+1,f[r-l+2]),add(r+2,f[r-l+1]);
		if (cnt) cout<<"NO\n"; else cout<<"YES\n";
	}
}