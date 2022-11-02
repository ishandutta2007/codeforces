#include<bits/stdc++.h>
const int N=100005,M=1000000007;
using namespace std;
int n,m,to[N*2],hd[N*2],lk[N],cnt=1,ans[2],
vis[N],f[2][2][N],now[2],tmp[2],deg[N];
bool cont[2][N],lu[N*2],lv[N*2];
inline void add(int u,int v,bool tu,bool tv){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
	lu[cnt]=tu,lv[cnt]=tv,deg[u]++;
}
int op,u,v;
bool tu,tv;
void dfs(int x,int y){
	for(int i=0;i<2;i++)
	if(cont[i][x])swap(f[0][i][x],f[1][i][x]);
	vis[x]=tu;
	bool qwq=0;
	for(int i=lk[x];i&&!qwq;i=hd[i])
	if(i^y){
		qwq=1;
		if(vis[to[i]]==tu){
			//cerr<<"End "<<x<<"~"<<to[i]<<endl;
			for(int j=0;j<2;j++)
			for(int k=0;k<2;k++){
				//cerr<<"wtf "<<x<<" "<<f[j][k][x]<<endl;
			(now[j^(k==lu[i]||tu==lv[i])]+=f[j][k][x])%=M;
			}
		}
		else{
			for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
			f[j][k][to[i]]=0;
			for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
			for(int l=0;l<2;l++)
			(f[j^(k==lu[i]||l==lv[i])][l][to[i]]+=f[j][k][x])%=M;
			dfs(to[i],i^1);
		}
	}
	if(!qwq)
	for(int i=0;i<2;i++)
	now[i]=((now[i]+f[i][0][x])%M+f[i][1][x])%M;
}
inline void sol(int i){
	if(vis[i]>=0)return;
	//cerr<<"Sol "<<i<<endl;
	now[0]=now[1]=0;
	tu=0;f[0][0][i]=1;
	f[0][1][i]=f[1][0][i]=f[1][1][i]=0;
	dfs(i,0);
	//cerr<<"---\n";
	tu=1;f[0][1][i]=1;
	f[0][0][i]=f[1][0][i]=f[1][1][i]=0;
	dfs(i,0);
	v=(ans[0]*1ll*now[0]+ans[1]*1ll*now[1])%M;
	ans[1]=(1ll*ans[1]*now[0]+1ll*ans[0]*now[1])%M;
	ans[0]=v;
	//cerr<<now[0]<<'/'<<now[1]<<endl;
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	vis[i]=-1;
	for(;m--;){
		scanf("%d%d",&op,&u);
		tu=u<0?u=-u,1:0;
		if(op<2)cont[tu][u]^=1;
		else{
			scanf("%d",&v);
			tv=v<0?v=-v,1:0;
			add(u,v,tu,tv);add(v,u,tv,tu);
		}
	}
	ans[0]=1;
	for(int i=1;i<=n;i++)
	if(deg[i]<2)sol(i);
	for(int i=1;i<=n;i++)sol(i);
	printf("%d",ans[1]);
}