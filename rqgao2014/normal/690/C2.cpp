#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

vi g[100005];
int ans,n,m,next[100005],maxx[100005];
bool vis[100005];

inline void add(int x,int y){
	g[x].pb(y);g[y].pb(x);
}
inline void dfs(int x){
	vis[x]=1;
	maxx[x]=0;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(vis[y]) continue;
		dfs(y);
		ans=max(ans,maxx[x]+maxx[y]+1);
		maxx[x]=max(maxx[x],maxx[y]+1);
	}
}

int main(){
	read(n,m);
	for(int i=1;i<=m;i++){
		int x,y;read(x,y);
		add(x,y);
	}dfs(1);
	printf("%d\n",ans);
	return 0;
}