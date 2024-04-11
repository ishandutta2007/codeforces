#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
#define y1 qwq
const int inf=1e15;
void solve()
{

	int n;
	cin>>n;
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	int posx,posy;
	if(x1==x2||x1==x3) posx=x1;
	else posx=x2;
	if(y1==y2||y1==y3) posy=y1;
	else posy=y2;
	int tx,ty;
	cin>>tx>>ty;
	if(posx==1&&(posy==1||posy==n))
	{
		if(tx==1||posy==ty) cout<<"YES\n";
		else cout<<"NO\n";
	}
	else if(posx==n&&(posy==1||posy==n))
	{
		if(tx==n||posy==ty) cout<<"YES\n";
		else cout<<"NO\n";
	}
	else
	{
		if((tx^posx)%2==0||(ty^posy)%2==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;cin>>T;
	while(T--) solve();
	return 0;
}