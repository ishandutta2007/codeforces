#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#include<random>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n;
int a[110];
int dp[110][110][2];
int get(int sum,int k,int us){
	int lft=sum^us,ned=k^us;
	if(lft==1){
		if(ned==1) return 1;
		return 0;
	}
	else{
		if(ned == 0) return 1;
		return 0;
	}
}
bool dfs(int x,int y,int k){
	if(dp[x][y][k]!=-1) return dp[x][y][k];
	if(x==0&&y==0){
		return k==0?1:0;
	}
	bool f=0;
	bool su=(x&1);
	if(x){
		f|=(!dfs(x-1,y,get(su,k,1)));
	}
	if(y){
		f|=(!dfs(x,y-1,get(su,k,0)));
	}
	return dp[x][y][k]=f;
}
int main(){
	memset(dp,-1,sizeof(dp));
	T=read();
	while(T--){
		n=read();
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) if(a[i]%2==0) cnt0++;else cnt1++;
		if(dfs(cnt1,cnt0,0)) printf("Alice\n");else printf("Bob\n");
	}
}