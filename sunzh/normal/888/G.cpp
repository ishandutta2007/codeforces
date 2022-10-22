#pragma GCC optimize(2,3,"Ofast","inline")
#include<iostream>
#include<cstdio>
#include<random>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int a[200010];
int trie[6000010][2];
int cnt;
int bel[6000010];
int id[6000010];
int fa[200010];
vector<int>vec[6000010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]); 
}
void insert(int x,int idx){
	int p=0;vec[p].pb(idx);
	for(int i=30;i>=0;--i){
		int t=(x>>i)&1;
		if(!trie[p][t]) trie[p][t]=++cnt;
		p=trie[p][t];vec[p].pb(idx);
	}
//	printf("p:%d,idx:%d\n",p,idx);
	id[p]=idx;
}
int dfs(int p,int x,int bit){
	if(bit==-1) return id[p];
	int t=(x>>bit)&1;
	int son=trie[p][t];
	if(son) return dfs(son,x,bit-1);
	else return dfs(trie[p][t^1],x,bit-1);
}
long long solve(int p,int bit){
	if(bit==-1) return 0;
	int l=trie[p][0],r=trie[p][1];
	if(!l||!r) return solve(l|r,bit-1);
	int mn=0x7f7f7f7f;
	for(int i:vec[l]){
		int t=dfs(r,a[i],bit-1);
		mn=min(mn,a[i]^a[t]);
	}
//	printf("p:%d,bit:%d,mn:%d\n",p,bit);
	return solve(l,bit-1)+solve(r,bit-1)+mn;
}
//mt19937 rnd(time(0));
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),fa[i]=i;
//	for(int i=1;i<=n;++i) printf("%d ",a[i]);printf("\n");
	for(int i=1;i<=n;++i) insert(a[i],i);
	printf("%lld\n",solve(0,30));
}