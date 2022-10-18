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
const int N=1e6+5,inf=1e9;
int n;
int l[N];
int cnt;
int ask(int x)
{
	cout<<"? "<<x<<endl;
	++cnt;
	int y=0;
//if (x<*max_element(l+1,l+n+1)) return inf;
//int cur=l[1];
//for (int i=2;i<=n;i++)
//{
//	if ((cur+l[i]+1)>x)
//	{
//		++y;
//		cur=l[i];
//	}
//	else cur+=l[i]+1;
//}
////cout<<"answer "<<y+1<<'\n';
//return y+1;
	cin>>y;
	return y?y:inf;
}
void answer(ll x)
{
	cout<<"! "<<x<<endl;
}
int w[N];
ll res=1e18;
void ztef(int l,int r,int ql,int qr)
{
	if (l>r||ql>qr) return;
	//dbg(l,r,ql,qr);
	if (ql==qr)
	{
		for (int i=l;i<=r;i++) w[i]=ql;
		return;
	}
	int m=ql+qr>>1;
	int x=ask(m);
	//assert(x==0||l<=x&&x<=r);
	if (x==inf)
	{
		ztef(l,r,m+1,qr);
	}
	else
	{
		ztef(x,r,ql,m);
		ztef(l,min(x-1,1),m+1,qr);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;res=n*2001;
//for (i=1;i<=n;i++) l[i]=rand()%2000+1;
//for (i=1;i<=n;i++) cin>>l[i];
	ztef(1,1,1,n*2001);
	for (i=1;i<=n;i++) res=min(res,(ll)(w[1]/i)*ask(w[1]/i));
//	for (i=1;i<=n;i++) cerr<<w[i]<<" \n"[i==n];
//	for (i=1;i<=n;i++)
//	{
//		//if (!(ask(w[i])<=i&&ask(w[i]-1)>i)) cerr<<i<<'\n';
//		//assert(ask(w[i])<=i&&(ask(w[i]-1)>i||ask(w[i]-1)==0));
//	}
	answer(res);
	//cerr<<cnt<<'\n';
//	assert(cnt<=n+30);
}