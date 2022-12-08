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

int n,ans,dp[300005][20],now,dep[300005];

inline void rise(int &x,int y){
	for(int i=0;i<20;i++) if(y&(1<<i)) x=dp[x][i];
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	rise(x,dep[x]-dep[y]);
	if(x==y) return x;
	for(int i=19;~i;i--)
		if(dp[x][i]!=dp[y][i]) x=dp[x][i],y=dp[y][i];
	return dp[x][0];
}
inline int get(int x,int y){
	int p=lca(x,y);
	return dep[x]+dep[y]-2*dep[p];
}

int main(){
	read(n);
	now=1;
	for(int i=2;i<=n;i++){
		int x;
		read(x);
		dep[i]=dep[x]+1;dp[i][0]=x;
		for(int j=1;j<20;j++)
			dp[i][j]=dp[dp[i][j-1]][j-1];
		if(dep[i]>dep[now]) ans++,now=i;
		ans=max(ans,get(i,now));
		printf("%d ",ans);
	}
	return 0;
}