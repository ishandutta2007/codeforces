#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 200005
using namespace std;
int n,to[N<<1],hd[N<<1],lk[N],cnt,
a[N],rk[N],q[N],h,t;
vector<int>ed[N];
bool cmp(int x,int y){
	return rk[x]<rk[y];
}
void dfs(int x,int y){
	for(int s,i=lk[x];i;i=hd[i])
	if((s=to[i])^y)
	ed[x].push_back(s),dfs(s,x);
	sort(ed[x].begin(),ed[x].end(),cmp);
}
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}
int u,v;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	scanf("%d%d",&u,&v),add(u,v),add(v,u);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i),rk[a[i]]=i;
	cnt=0;dfs(1,0);
	h=t=1,q[t++]=1;
	for(;h^t;){
		u=q[h++];
		for(int i=0;i<ed[u].size();i++)
		q[t++]=ed[u][i];
	}
	for(int i=1;i<=n;i++)
	if(q[i]^a[i])return puts("No"),0;
	puts("Yes");
}