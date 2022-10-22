#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[200010];
int trie[6000010][2];
int p[200010],id[6000010];
int cnt;
int sz[6000010];
int fa[6000010];
void insert(int x,int i){
	int k=30;
	int pos=0;
	while(k>=0){
		++sz[pos];
//		printf("i:%d,k:%d,x:%d\n",i,k,(x&(1<<k))>>k);
		if(trie[pos][(x&(1<<k))>>k]) pos=trie[pos][(x&(1<<k))>>k];
		else{
			trie[pos][(x&(1<<k))>>k]=++cnt;
			fa[cnt]=pos;
			pos=cnt;
		}
		--k;
	}
	++sz[pos];
	id[pos]=i,p[i]=pos;
}
int dfs(int x){
	if(trie[x][0]&&trie[x][1]){
		int s1=dfs(trie[x][0])+sz[trie[x][1]]-1;
		int s2=dfs(trie[x][1])+sz[trie[x][0]]-1;
		return min(s1,s2);
	}
	else if(trie[x][0]) return dfs(trie[x][0]);
	else if(trie[x][1]) return dfs(trie[x][1]);
	else return 0;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		insert(a[i],i);
	}
	printf("%d\n",dfs(0));
}