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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,x,y;
vector<int>dp[45];
int val[45];
void clean(vector<int>&vec){
	vector<int>c;swap(vec,c);return ;
}
int main(){
	n=read(),x=read(),y=read();
	--n;
	for(int i=0;i<x+y;++i) val[i]=(n/(x+y))+(i<=(n%(x+y)));
	dp[0].resize(2);
	dp[0][0]=0,dp[0][1]=val[0];
	int ans=0;
	for(int i=1;i<x+y;++i){
		dp[i].resize(1<<(min(i+1,max(x,y)+1)));
		for(int S=0;S<(1<<min(i,max(x,y)+1));++S){
			int T=((S<<1)&((1<<(min(i+1,max(x,y)+1)))-1));
			if((T&(1<<y))==0&&(T&(1<<x))==0) dp[i][T|1]=max(dp[i][T|1],dp[i-1][S]+val[i]);
			dp[i][T]=max(dp[i][T],dp[i-1][S]);
		}
		clean(dp[i-1]);
	}
	for(int S=0;S<(1<<max(x,y)+1);++S) ans=max(ans,dp[x+y-1][S]);
	printf("%d\n",ans);
}