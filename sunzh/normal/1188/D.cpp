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
#define int long long
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
int a[100010];
int dp[65][100010];
int id[100010];
int lft[100010],rgt[100010];
signed main(){
	n=read();
	memset(dp,0x15,sizeof(dp));
	dp[0][0]=0;
//	memset(dp[0],0,sizeof(dp[0]));
	for(int i=1;i<=n;++i)  a[i]=read(),id[i]=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) a[i]=a[n]-a[i];
	sort(a+1,a+n+1);
	for(int i=0;i<=62;++i){
		int lsz,rsz;lsz=rsz=0;
		for(int j=1;j<=n;++j){
			if(a[id[j]]&(1ll<<i)) lft[++lsz]=id[j];
			else rgt[++rsz]=id[j];
		}
//		printf("i:%d,lsz:%d,rsz:%d\n",i,lsz,rsz);
		int lpos,rpos;
		lpos=rpos=1;
		for(int j=0;j<=n;++j){
			if(lpos<=lsz&&lft[lpos]==id[j]) ++lpos;
			if(rpos<=rsz&&rgt[rpos]==id[j]) ++rpos;
//			printf("j:%d,lpos:%d,rpos:%d\n",j,lpos,rpos);
			dp[i+1][lpos-1]=min(dp[i+1][lpos-1],dp[i][j]+rpos-1+lsz-lpos+1);// 0
			dp[i+1][lsz+rpos-1]=min(dp[i+1][lsz+rpos-1],dp[i][j]+rsz-rpos+1+lpos-1);// 1
		}
		int c=0;
		for(int j=1;j<=lsz;++j) id[++c]=lft[j];
		for(int j=1;j<=rsz;++j) id[++c]=rgt[j];
	}
	printf("%lld\n",dp[63][0]);
}