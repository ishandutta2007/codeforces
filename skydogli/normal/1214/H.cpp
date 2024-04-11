#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 200005
int n,k,rt;
int fa[MN],col[MN],dep[MN],tag[MN];
vector<int>edge[MN];
void DFS(int x){
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;
		col[v]=col[x]%k+1;
		DFS(v);
	}
}
void dfs(int x){
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;dep[v]=dep[x]+1;
		col[v]=(col[x])%k+1;
		dfs(v);
	}
	if(dep[x]>dep[rt])rt=x;
}
void Find(int x,int A,int B,int lst){
	if(A>=k-1&&B>=k-1&&!tag[x]){puts("No");exit(0);}
	if(!tag[x]){
		if(A>B)col[x]=lst%k+1;
		else col[x]=(lst+k-2)%k+1;
	}
	else tag[x]=lst%k+1;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;
		if(tag[v])Find(v,A+1,B-1,col[x]);
		else Find(v,A+1,B+1,col[x]);
	}
}
int main(){
	n=read();k=read();
	for(int i=1;i<n;++i){
		int x=read(),y=read();
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	if(k==2){
		col[1]=1;DFS(1);
		puts("Yes");
		for(int i=1;i<=n;++i)printf("%d ",col[i]);
		return 0;
	}
	dfs(1);fa[rt]=0;dep[rt]=0;
	int tmp=rt;dfs(rt);swap(tmp,rt);
	int x=tmp;
	while(x)tag[x]=1,x=fa[x];
	Find(rt,0,dep[tmp],k);	
//	cerr<<"E: "<<rt<<" "<<tmp<<endl;
//	col[rt]=1;
//	for(int i=1;i<=n;++i)dep[i]=0;
//	dfs(rt);dfs(tmp);
	puts("Yes");
	for(int i=1;i<=n;++i)printf("%d ",col[i]);
	return 0;
}