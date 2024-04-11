#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
long long l,r;
long long dp[20][3010][50];
int a[20];
int tot;
int ha[3010];
const int M=2520;
int _lcm(int x,int y){
	return x*y/__gcd(x,y);
}
long long dfs(int p,int lcm,int x,bool f){
	if(p==0) return x%lcm==0;
	if(!ha[lcm]) ha[lcm]=++tot;
	if(!f&&dp[p][x][ha[lcm]]!=-1) return dp[p][x][ha[lcm]];
	long long ans=0;
	int maxn=(f==1?a[p]:9);
	for(int i=0;i<=maxn;++i){
		ans=ans+dfs(p-1,_lcm(i<1?1:i,lcm),(x*10+i)%M,f&(i==a[p]));
	}
	if(!f) dp[p][x][ha[lcm]]=ans;
	return ans;
}
long long solve(long long x){
	int cnt=0;
	while(x){
		a[++cnt]=x%10;x/=10;
	} 
	return dfs(cnt,1,0,1);
}
int main(){
	memset(dp,-1,sizeof(dp));
	T=read();
	while(T--){
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",solve(r)-solve(l-1));
	}
	return 0;
}