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
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n;
const int mod=1e9+7;
char s[1000010];
int nxt[1000010];
int dp[1000010];
int len[1000010];
int nxt1[1000010],nxtd[1000010],lst[1000010];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int t=n+1;
	for(int i=n;i>=1;--i){
		nxt1[i]=t;
		if(s[i]=='1') t=i;
	}
	for(int i=1;i<=n;++i){
		lst[i]=n+1;
		if(s[i]=='0') len[i]=len[i-1]+1;
	}
	for(int i=n;i>=1;--i){
		if(s[i]=='0'){
			nxtd[i]=lst[len[i]+1];
			lst[len[i]]=i;
		}
		else nxtd[i]=lst[1];
	}
	int st=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1'){
			st=i;
			break ;
		}
	}
	if(st==0){
		printf("%d\n",n);return 0;
	}
	dp[st]=st;
	for(int i=st;i<n;++i){
		if(nxt1[i]!=n+1){
			dp[nxt1[i]]=(dp[nxt1[i]]+dp[i])%mod;
		}
		if(nxtd[i]!=n+1){
			dp[nxtd[i]]=(dp[nxtd[i]]+dp[i])%mod;
		}
	}
	int ans=0;
	for(int i=st;i<=n;++i){
		if(len[i]<=len[n]) ans=(ans+dp[i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}