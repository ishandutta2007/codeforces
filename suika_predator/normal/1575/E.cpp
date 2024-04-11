#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 410000;
const int mod  = 1e9+7;
const int mod2 = (mod+1)>>1;
inline void add(int &a,const int &b){ a+=b;if(a>=mod)a-=mod; }
inline void dec(int &a,const int &b){ a-=b;if(a<0)a+=mod; }

int n,K;
int a[maxn];
vector< pair<int,int> >V[maxn];

int v[maxn];

int siz[maxn],Siz,root;
void dfs(const int x,const int fa)
{
	siz[x]=1;
	for(auto y:V[x]) if(y.first!=fa&&!v[y.first])
	{
		dfs(y.first,x);
		siz[x]+=siz[y.first];
	}
}
void findroot(const int x,const int fa)
{
	int mxs=0;
	for(auto y:V[x]) if(y.first!=fa&&!v[y.first])
	{
		findroot(y.first,x);
		mxs=max(mxs,siz[y.first]);
	}
	if(mxs*2<=Siz&&(Siz-siz[x])*2<=Siz) root=x;
}
int f[2][maxn],g[2][maxn],uf;
int sf[2][maxn],sg[2][maxn];
int tuf,trc;
int ans;
void add(const int x,const int fa,const int now,const int sumk,const int suma)
{
	add(f[trc][sumk],suma);
	add(g[trc][sumk],1);
	for(auto temp:V[x])
	{
		int y=temp.first;
		if(y!=fa&&!v[y])
			add(y,x,temp.second,sumk+(now!=temp.second),(suma+a[y])%mod);
	}
	tuf=max(tuf,sumk);
}
void cal(const int x,const int fa,const int now,const int sumk,const int suma)
{
	if(sumk>K) return;
	
	if(sumk<=K) add(ans,(ll)suma*2%mod);
	for(int j=0;j<2;j++) if(sumk+(j!=trc)<=K)
	{
		int ui = min(uf,K-sumk+(j==trc));
		int tf=sf[j][ui],tg=sg[j][ui];
		dec(tf,f[j][min(ui,tuf)]);
		dec(tg,g[j][min(ui,tuf)]);
		
		add(ans,(ll)tg*suma%mod);
		add(ans,tf);
	}
	
	for(auto temp:V[x])
	{
		int y=temp.first;
		if(y!=fa&&!v[y])
			cal(y,x,temp.second,sumk+(now!=temp.second),(suma+a[y])%mod);
	}
}
void Divide(int x)
{
	dfs(x,0);
	Siz=siz[x]; findroot(x,0);
	x=root;
	
	uf=Siz;
	for(auto temp:V[x])
	{
		int y=temp.first;
		if(!v[y]) 
		{
			trc=temp.second;
			add(y,x,temp.second,1,a[y]);
		}
	}
	for(int j=0;j<2;j++)
	{
		sf[j][0]=f[j][0]; sg[j][0]=g[j][0];
		f[j][0]=0, g[j][0]=0;
		for(int i=1;i<=uf;i++) 
		{
			sf[j][i]=( sf[j][i-1]+f[j][i] )%mod;
			f[j][i]=0;
			sg[j][i]=( sg[j][i-1]+g[j][i] )%mod;
			g[j][i]=0;
		}
	}
	
	for(auto temp:V[x])
	{
		int y=temp.first;
		if(!v[y])
		{
			tuf=0; trc=temp.second;
			add(y,x,temp.second,1,a[y]);
			for(int j=0;j<2;j++) for(int i=1;i<=tuf;i++)
			{
				f[j][i]=(f[j][i-1]+f[j][i])%mod;
				g[j][i]=(g[j][i-1]+g[j][i])%mod;
			}
			cal(y,x,temp.second,1,(a[x]+a[y])%mod);
			for(int j=0;j<2;j++) for(int i=0;i<=tuf;i++)
			{
				f[j][i]=g[j][i]=0;
			}
		}
	}
	
	v[x]=1;
	for(auto temp:V[x])
	{
		int y=temp.first;
		if(!v[y]) Divide(y);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>K; K++;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int x,y,ti; cin>>x>>y>>ti;
		V[x].push_back( make_pair(y,ti) ); V[y].push_back( make_pair(x,ti) );
	}
	
	Divide(1);
	ans=(ll)ans*mod2%mod;
	for(int i=1;i<=n;i++) add(ans,a[i]);
	
	cout<<ans<<endl;
	
	return 0;
}