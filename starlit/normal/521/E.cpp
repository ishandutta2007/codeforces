#include<bits/stdc++.h>
const int N=200005;
using namespace std;
int n,m,to[N*2],hd[N*2],lk[N],cnt=1,
dfn[N],low[N],st[N],h,t,now,vis[N],
nxt[N],inc[N];
vector<int>ed[N];
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}int u,v;
bool ins[N],qwq[N];
void print(int x){
	t++;
	if(x^v)print(nxt[x]);
	else printf("\n%d",t);
	printf(" %d",x);
}
void dfss(int x){
	if(qwq[x])return;
	st[t++]=x,qwq[x]=1;
	if(inc[x]>1){
		printf("%d",t);
		for(int i=0;i<t;i++)
		printf(" %d",st[i]);
		t=1;
		for(int i=v;;){
			st[t++]=i=nxt[i];
			if(i==x)break;
		}
		printf("\n%d",t);
		for(int i=0;i<t;i++)
		printf(" %d",st[i]);
		t=0;print(x);
		exit(0);
	}
	for(int i:ed[x])dfss(i);
	t--;
}
void sol(){
	if(h+3>=t)return;
	now++;int pt=0;
	//for(int i=h;i<t;i++)
	//cerr<<"("<<to[st[i]]<<"~"<<to[st[i]^1]<<")";
	//cerr<<endl;
	for(int i=h;i<t;i++){
		u=to[st[i]],v=to[st[i]^1];
		if(vis[u]<now)vis[u]=now,pt++;
		if(vis[v]<now)vis[v]=now,pt++;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	if(pt==t-h)return;
	puts("YES"),m=0;
	for(int i=u,ls=0;;){
		inc[i]=1;
		assert(ed[i].size()>1);
		for(int s:ed[i])
		if(s^ls){nxt[i]=s,ls=i,i=s;break;}
		if(inc[i]){u=i;break;}
	}
	v=0;
	for(int i=u;;){
	//cerr<<i<<"...";
		inc[i]=2,i=nxt[i];
		if(ed[i].size()>2)v=i;
		if(i==u)break;
	}
	assert(v);
	//cerr<<v<<endl;
	st[0]=v,t=qwq[v]=1;
	for(int i:ed[v])
	if(inc[i]<2||nxt[v]!=i&&nxt[i]!=v)dfss(i);
}
void dfs(int x,int y){
	dfn[x]=low[x]=++cnt,ins[x]=1;
	//cerr<<"dfs "<<x<<endl;
	for(int s,i=lk[x];i;i=hd[i])
	if(i^y){
		if(!dfn[s=to[i]]){
			st[t++]=i;//cerr<<"Ins "<<to[i]<<','<<to[i^1]<<endl;
			dfs(s,i^1);
			low[x]=min(low[x],low[s]);
			//cerr<<s<<"&"<<x<<":"<<low[s]<<','<<dfn[x]<<endl;
			if(low[s]>=dfn[x]){
				for(h=t;st[h]^i;){
				if(!h)exit(-1);
				--h,ed[to[st[h]]].clear(),
				ed[to[st[h]^1]].clear();
				}
				
				//cerr<<"pop "<<to[st[h]]<<','<<to[st[h]^1]<<endl;
				sol();t=h;
			}
		}
		else if(ins[s])//cerr<<"ins "<<to[i]<<','<<to[i^1]<<endl,
		st[t++]=i,low[x]=min(low[x],dfn[s]);
	}ins[x]=0;
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(;m--;)
	scanf("%d%d",&u,&v),
	add(u,v),add(v,u);
	for(int i=1;i<=n;i++)
	if(!dfn[i])dfs(i,0);
	puts("NO");
}