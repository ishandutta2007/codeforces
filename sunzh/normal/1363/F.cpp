#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cstdio>
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
int T;
int n;
char s[2010],t[2010];
int dp[2010][2010];
int cnts[2010][30],cntt[2010][30]; 
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);scanf("%s",t+1);
		while(s[n]==t[n]&&n>0) --n;
		if(n==0){
			printf("0\n");continue ;
		}
		for(int i=1;i<=n;++i)
			for(int j=0;j<=n;++j) dp[i][j]=0x7f3f3f3f;
		for(int i=0;i<=n;++i) dp[0][i]=i;
		for(int i=1;i<=n+1;++i) for(int j=1;j<=26;++j) cnts[i][j]=cntt[i][j]=0;
		for(int i=n;i>=1;--i){
			for(int j=1;j<=26;++j){
				cnts[i][j]=cnts[i+1][j]+(s[i]-'a'+1==j);
				cntt[i][j]=cntt[i+1][j]+(t[i]-'a'+1==j);
			}
		}
		bool flag=0;
		for(int i=1;i<=26;++i) if(cnts[1][i]!=cntt[1][i]){ flag=1; break ;}
		if(flag==1){
			printf("-1\n");continue ;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(cnts[i+1][t[j]-'a'+1]>cntt[j+1][t[j]-'a'+1]) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
				if(s[i]==t[j]) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
				dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
			}
		}
		printf("%d\n",dp[n][n]>=0x3f3f3f3f?-1:(dp[n][n]>>1));
	}
	return 0;
}