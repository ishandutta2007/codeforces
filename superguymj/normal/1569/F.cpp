#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define pb push_back

using namespace std;
const int N=15,M=64;
typedef long long LL;
int n,m,k,col[N],_col[N],id[N],fa[N],siz[N],pr[N][2];
LL ans,c[N][N],flv[N];
bool f[M][N][2],mp[N][N];
vector <vector <int>> vt;
map <vector <int>,bool> cnt;

void find(int x,int c)
{
	if(x>(n>>1))	
	{
		vector <int> p;
		rep(i,1,(n>>1)) p.pb(col[i]);
		vt.pb(p);
		return;
	}
	rep(i,1,c) col[x]=i,find(x+1,c);
	col[x]=c+1,find(x+1,c+1);
}

void init()
{
	flv[0]=1;
	rep(i,1,k) flv[i]=flv[i-1]*i;
	rep(i,0,k) c[i][0]=1;
	rep(i,1,k) rep(j,1,i) c[i][j]=c[i-1][j-1]+c[i-1][j];
	col[1]=1,find(2,1);
}

bool check()
{
	int cnt=0;
	rep(i,1,n) if(fa[i]==i) pr[id[i]=++cnt][0]=i,col[i]=cnt; else pr[id[fa[i]]][1]=i,col[i]=col[fa[i]];
	if(cnt!=(n>>1)) return 0;
	memset(f,0,sizeof(f));
	rep(i,1,cnt) f[1<<i-1][i][0]=1;
	rep(i,1,(1<<cnt)-2)
		rep(j,1,cnt) rep(k,0,1) if(f[i][j][k])
		{
			int x=pr[j][0],y=pr[j][1];
			if(k) swap(x,y);
			rep(l,1,cnt) if(!(i&(1<<l-1))) rep(o,0,1)
			{
				int _x=pr[l][0],_y=pr[l][1];
				if(o) swap(_x,_y);
				if(mp[x][_x] && mp[y][_y])
					f[i|(1<<l-1)][l][o]=1;	
			}
		}
	bool jdg=0;
	rep(i,1,cnt) if(mp[pr[i][0]][pr[i][1]])
		if(f[(1<<cnt)-1][i][0] || f[(1<<cnt)-1][i][1]) jdg=1;
	return jdg;
}

void trf(vector <int> p,int col[])
{
	int mx=0;
	rep(i,0,(n>>1)-1) mx=max(mx,p[i]);
	rep(i,1,n) _col[i]=p[col[i]-1];
	vector <int> q;
	rep(i,1,n) q.pb(_col[i]);
	if(!cnt[q]) cnt[q]=1,ans+=c[k][mx]*flv[mx];
}

void match(int x)
{
	if(x>n)
	{
		if(check())
		{
			int sz=vt.size();
			rep(i,0,sz-1)
				trf(vt[i],col);
		}
		return;
	}
	fa[x]=x,match(x+1);
	rep(i,1,x-1) if(!siz[fa[i]])
		siz[fa[i]]=1,fa[x]=fa[i],match(x+1),siz[fa[i]]=0;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mp[x][y]=mp[y][x]=1;
	}
	init();
	match(1);
	printf("%lld\n",ans);
	return 0;
}