#include<bits/stdc++.h>

#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m,s,b,kk,hh,tot,now,ans;
ll x[1005],a[1005],f[1005],y[1005],d[1005],v[2000005],nxt[2000005],h[2005],c[105][105],mch[2005];
pll tmp[1005];
bool vis[2005];

void addedge(int xx,int yy){
	v[++tot]=yy; nxt[tot]=h[xx]; h[xx]=tot;
	v[++tot]=xx; nxt[tot]=h[yy]; h[yy]=tot;
}

bool dfs(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		vis[v[p]]=true;
		if(!mch[v[p]]||dfs(mch[v[p]])){
			mch[v[p]]=u;
			return true;
		}
	}
	return false;
}

int main(){
	n=readint(); m=readint();
	memset(c,0x3f,sizeof(c));
	int xx,yy;
	for(int i=1;i<=m;i++){
		xx=readint(); yy=readint();
		c[xx][yy]=c[yy][xx]=1;
	}
	for(int i=1;i<=n;i++) c[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
	s=readint(); b=readint(); kk=readint(); hh=readint();
	for(int i=1;i<=s;i++) x[i]=readint(),a[i]=readint(),f[i]=readint();
	for(int i=1;i<=s;i++) tmp[i]=mp(a[i],1ll*i);
	sort(tmp+1,tmp+s+1);
	reverse(tmp+1,tmp+s+1);
	for(int i=1;i<=b;i++) y[i]=readint(),d[i]=readint();
	for(int i=1;i<=s;i++) for(int j=1;j<=b;j++) if(c[x[i]][y[j]]<=f[i]&&a[i]>=d[j]) addedge(i,j+s);
	ans=now=s*hh;
	for(int i=1;i<=s;i++){
		now-=hh;
		memset(vis,false,sizeof(vis));
		if(dfs(tmp[i].se)) now+=kk;
		ans=min(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}