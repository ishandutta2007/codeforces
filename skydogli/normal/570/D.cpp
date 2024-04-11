#include<bits/stdc++.h>
using namespace std;
#define MN 500005
inline int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int dep[MN],siz[MN],w[MN],fa[MN],ans[MN];
int n,m,st[MN];
char ch[MN];
vector<int>edge[MN];
struct data{
	int id,h;
	data(int I=0,int H=0){
		id=I;h=H;
	}
};
vector<data>Q[MN];
inline bool chk(register int x){return (x-(x&(-x)))==0;}
void add(int x){st[dep[x]]^=1<<(ch[x]-'a');}
void work(int x){
	for(int i=0;i<Q[x].size();++i){
		ans[Q[x][i].id]=st[Q[x][i].h];
	}
	add(x);
	for(int i=0;i<edge[x].size();++i)
		work(edge[x][i]);
	for(int i=0;i<Q[x].size();++i){
		ans[Q[x][i].id]=chk(ans[Q[x][i].id]^st[Q[x][i].h]);
	}
}
int main(){
	n=read();m=read();
	dep[1]=1;
	for(int i=2;i<=n;++i){
		fa[i]=read();
		dep[i]=dep[fa[i]]+1;
		edge[fa[i]].push_back(i);
	}
	scanf("%s",ch+1);
	for(int i=1;i<=m;++i){
		int v=read(),h=read();
		Q[v].push_back(data(i,h));
	}
	work(1);
	for(int i=1;i<=m;++i)puts(ans[i]?"Yes":"No");
	return 0;
}