#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define range(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n)
{
	unsigned int x=rnd();
	return x%n+1;
}
#define rand fst
const int p=998244353;
const db eps=1e-9;
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
inline int ksm(register int x,register int y)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int> > ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=1e6+2,M=1e6+2,inf=1e9;
char s[N];
int a[N],b[N],c[N],d[N],e[N],f[N];
int xz[N],yz[N],sx[N],sy[N],nx[N],ny[N],px[N],py[N],sxz[N],syz[N];
int T,n,m,q,xs,ys,i,j,k,x,y,z,la,ksiz,ks;
vector<int> bel[N];
ll ans;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	cin>>T;
	while (T--)
	{
		cin>>n>>m>>q;xs=ys=ans=0;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=m;i++) cin>>b[i];
		for (i=1;i<=q;i++) cin>>c[i]>>d[i];
		for (i=1;i<=n;i++) e[++xs]=a[i];
		for (i=1;i<=q;i++) e[++xs]=c[i];
		sort(e+1,e+xs+1);xs=unique(e+1,e+xs+1)-e-1;
		for (i=1;i<=n;i++) a[i]=lower_bound(e+1,e+xs+1,a[i])-e;
		for (i=1;i<=q;i++) c[i]=lower_bound(e+1,e+xs+1,c[i])-e;
		for (i=1;i<=m;i++) f[++ys]=b[i];
		for (i=1;i<=q;i++) f[++ys]=d[i];
		sort(f+1,f+ys+1);ys=unique(f+1,f+ys+1)-f-1;
		for (i=1;i<=m;i++) b[i]=lower_bound(f+1,f+ys+1,b[i])-f;
		for (i=1;i<=q;i++) d[i]=lower_bound(f+1,f+ys+1,d[i])-f;
		for (i=1;i<=q;i++) xz[c[i]]=yz[d[i]]=0;
		for (i=1;i<=n;i++) xz[a[i]]=1;
		for (i=1;i<=m;i++) yz[b[i]]=1;
		for (i=1;i<=xs;i++) sxz[i]=sxz[i-1]+xz[i];
		for (i=1;i<=ys;i++) syz[i]=syz[i-1]+yz[i];
		for (i=1;i<=xs;i++) sx[i]=0;
		for (i=1;i<=ys;i++) sy[i]=0;
		for (i=1;i<=q;i++) if (xz[c[i]]+yz[d[i]]!=2)
		{
			assert(xz[c[i]]||yz[d[i]]);
			//cout<<c[i]<<' '<<d[i]<<'\n';
			if (yz[d[i]]) ++sx[c[i]]; else ++sy[d[i]];
		}
		for (i=1;i<=xs;i++) sx[i]+=sx[i-1];
		for (i=1;i<=ys;i++) sy[i]+=sy[i-1];
		for (i=xs;i;i--) nx[i]=xz[i]?i:nx[i+1];
		for (i=ys;i;i--) ny[i]=yz[i]?i:ny[i+1];
		for (i=1;i<=xs;i++) px[i]=xz[i]?i:px[i-1];
		for (i=1;i<=ys;i++) py[i]=yz[i]?i:py[i-1];
		//for (i=1;i<=xs;i++) cout<<e[i]<<" \n"[i==xs];
		//for (i=1;i<=xs;i++) cout<<sx[i]<<" \n"[i==xs];
		//for (i=1;i<=xs;i++) cout<<nx[i]<<" \n"[i==xs];
		//for (i=1;i<=xs;i++) cout<<px[i]<<" \n"[i==xs];
		for (i=1;i<=q;i++) if (xz[c[i]]+yz[d[i]]!=2)
		{
			if (xz[c[i]]) ans+=sy[ny[d[i]]]-sy[py[d[i]]]-1;
			else ans+=sx[nx[c[i]]]-sx[px[c[i]]]-1;
		}
		ans>>=1;
		for (i=1;i<=ys;i++) bel[i].clear();
		for (i=1;i<=q;i++) if (xz[c[i]]+yz[d[i]]!=2&&yz[d[i]]) bel[d[i]].push_back(c[i]);
		for (i=1;i<=ys;i++)
		{
			sort(bel[i].begin(),bel[i].end());
			//for (auto u:bel[i]) cout<<u<<" ";cout<<"\n";
			for (j=0;j+1<bel[i].size();j++) if (sxz[bel[i][j]]==sxz[bel[i][j+1]])
			{
				k=j+1;
				while (k+1<bel[i].size()&&sxz[bel[i][j]]==sxz[bel[i][k+1]]) ++k;
				ans-=(ll)(k-j+1)*(k-j)>>1;
				j=k;
			}
				//cout<<ans<<endl;
		}
		for (i=1;i<=xs;i++) bel[i].clear();
		for (i=1;i<=q;i++) if (xz[c[i]]+yz[d[i]]!=2&&xz[c[i]]) bel[c[i]].push_back(d[i]);
		for (i=1;i<=xs;i++)
		{
			sort(bel[i].begin(),bel[i].end());
			//for (auto u:bel[i]) cout<<u<<" ";cout<<"\n";
			for (j=0;j+1<bel[i].size();j++) if (syz[bel[i][j]]==syz[bel[i][j+1]])
			{
				k=j+1;
				while (k+1<bel[i].size()&&syz[bel[i][j]]==syz[bel[i][k+1]]) ++k;
				ans-=(ll)(k-j+1)*(k-j)>>1;
				j=k;
			}
		}
		cout<<ans<<'\n';
	}
}