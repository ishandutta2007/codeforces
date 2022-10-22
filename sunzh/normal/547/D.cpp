#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define PII pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
const int maxn=2e5;
int n;
vector<PII>vec[400010];
int m;
bool vis[600010];
int ans[600010];
vector<PII>::iterator it[400010];
void dfs(int x){
	while(it[x]!=vec[x].end()){
		int i=it[x]->se,v=it[x]->fi;++it[x];
		if(vis[i]){
			continue ;
		}
		vis[i]=1;
		ans[i]=(x>maxn);
		dfs(v);
		break ;
	}
}
int main(){
	n=read();m=n;
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		vec[x].emplace_back(y+maxn,i);
		vec[y+maxn].emplace_back(x,i);
	}
	for(int i=1;i<=(maxn<<1);++i){
		if(vec[i].size()&1){
			vec[i].emplace_back(0,++m);vec[0].emplace_back(i,m);
		}
	}
	for(int i=0;i<=(maxn<<1);++i) it[i]=vec[i].begin();
	for(int i=0;i<=(maxn<<1);++i) dfs(i);
	for(int i=1;i<=n;++i) {
		putchar(ans[i]==1?'r':'b');
	}
	putchar('\n');
	return 0;
}