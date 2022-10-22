#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int stk1[300010];
int stk2[300010];
int tp1,tp2;
int dp[300010];
int n;
int h[300010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) h[i]=read();
	stk1[++tp1]=1;stk2[++tp2]=1;
	dp[1]=0;
	for(int i=2;i<=n;++i){
		dp[i]=dp[i-1]+1;
		while(tp1&&h[stk1[tp1]]>h[i]){
			--tp1;
			if(tp1) dp[i]=min(dp[i],dp[stk1[tp1]]+1);
		}
		if(tp1&&h[stk1[tp1]]==h[i]) dp[i]=min(dp[i],dp[stk1[tp1]]+1),stk1[tp1]=i;
		else stk1[++tp1]=i;
		while(tp2&&h[stk2[tp2]]<h[i]){
			--tp2;
			if(tp2) dp[i]=min(dp[i],dp[stk2[tp2]]+1); 
		}
		if(tp2&&h[stk2[tp2]]==h[i]) dp[i]=min(dp[i],dp[stk2[tp2]]+1),stk2[tp2]=i;
		else stk2[++tp2]=i;
	}
	printf("%d\n",dp[n]);
	return 0;
}