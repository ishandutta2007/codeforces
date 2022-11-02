#include<bits/stdc++.h>
const int N=300005;
using namespace std;
int n,m,ans=2e9,co[N],ti[N],
to[N*3],hd[N*3],lk[N],cnt,tot,deg[N],
dfn[N],low[N],st[N],t,scc[N],nxt[N],
q[N],h,Hd[N];
bool ins[N],nc[N];
vector<int>ed[N],ss;
int u,v,mi;
bool cmp(int x,int y){return co[x]<co[y];}
inline void add(int x,int y){
	//cerr<<x<<"->"<<y<<endl;
	to[++cnt]=x,hd[cnt]=lk[y],lk[y]=cnt;
}
inline void Add(int x,bool xd,int y,bool yd){
	add(3*m*xd+x,3*m*yd+y);
	add(3*m*(yd^1)+y,3*m*(xd^1)+x);
}
void dfs(int x){
	dfn[x]=low[x]=++cnt,ins[x]=1,st[t++]=x;
	for(int s,i=lk[x];i;i=hd[i])
	if(!dfn[s=to[i]])dfs(s),low[x]=min(low[x],low[s]);
	else if(ins[s])low[x]=min(low[x],dfn[s]);
	if(dfn[x]==low[x]){
		for(tot++,v=0;st[t]^x;)
		nxt[u=st[--t]]=v,
		ins[u]=0,scc[v=u]=tot;
		Hd[tot]=v;
	}
}
inline bool chk(){
	//cerr<<"check "<<mi<<endl;
	for(int i=1;i<=m*6;i++)
	lk[i]=dfn[i]=nxt[i]=deg[i]=nc[i]=0;
	cnt=0,tot=m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<ed[i].size();j++){
			u=ed[i][j];
			Add(u,0,++tot,0);
			if(ti[u]>mi)add(u,3*m+u);
			if(j){
				v=ed[i][j-1];
				if(co[u]==co[v])Add(u,1,v,0);
				Add(tot-1,0,tot,0);
				Add(u,0,tot-1,1);
			}
		}
	}tot=0;
	for(int i=1;i<=m*6;i++)
	if(!dfn[i])dfs(i);
	for(int i=1;i<=3*m;i++)
	if(scc[i]==scc[i+3*m])return 0;
	//cerr<<"OK\n";
	//for(int i=1;i<=6*m;i++)
	//cerr<<i<<":"<<scc[i]<<endl;
	ss.clear();
	for(int i=1;i<=6*m;i++)
	for(int j=lk[i];j;j=hd[j])
	if(scc[to[j]]^scc[i])
	//cerr<<"real:"<<to[j]<<'('<<scc[to[j]]<<")<-"<<i<<'('<<scc[i]<<")\n",
	deg[scc[to[j]]]++;
	t=0;
	//cerr<<deg[7]<<"?????\n";
	for(int i=1;i<=tot;i++)
	if(!deg[i])q[t++]=i;
	for(int h=0;h<t;){
		u=q[h++];
		if(nc[u])continue;
		//cerr<<"Choose "<<Hd[u]<<endl;
		for(int i=Hd[u];i;i=nxt[i]){
			//cerr<<"choose "<<i<<endl;
			if(i<=m)ss.push_back(i);
			nc[scc[i+(i>3*m?-3:3)*m]]=1;
			for(int s,j=lk[i];j;j=hd[j])
			if((s=scc[to[j]])^scc[i])
			if(!--deg[s])q[t++]=s;
		}
	}
	return 1;
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d%d",&u,&v,co+i,ti+i),
	ed[u].push_back(i),ed[v].push_back(i);
	for(int i=1;i<=n;i++){
		sort(ed[i].begin(),ed[i].end(),cmp);
		for(int j=u=0;j<ed[i].size();j++){
			if(co[ed[i][u]]^co[ed[i][j]])u=j;
			if(u+1<j)return puts("No"),0;
		}
	}
	for(int l=0,r=1e9;l<=r;){
		mi=l+r>>1;
		if(chk())ans=mi,r=mi-1;
		else l=mi+1;
	}
	if(ans<2e9){
		printf("Yes\n%d %d\n",ans,ss.size());
		for(int i:ss)printf("%d ",i);
	}else puts("No");
}