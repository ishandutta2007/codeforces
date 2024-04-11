#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,k;
long long ans;
struct node{
	int l,r,a;
}a[2010];
long long dp[2010];
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i].l=read(),a[i].r=read(),a[i].a=read();
	int m=0;
	for(int i=1;i<=n;++i){
		if(a[i].l==a[m].l&&a[i].r==a[m].r) a[m].a+=a[i].a;
		else a[++m]=a[i];
	}
	for(int i=m;i>=1;--i){
		int nd=a[i].a+(a[i].r==a[i+1].l?dp[i+1]:0);
		dp[i]=nd-1ll*(a[i].r-a[i].l)*k;
		if(dp[i]>k){
			printf("-1\n");return 0;
		}
		dp[i]=max(0ll,dp[i]);
	}
	long long cnt=0;
	for(int i=1;i<=m;++i){
		if(cnt<dp[i]) ans+=cnt,cnt=k;
		ans+=a[i].a;
		(cnt-=a[i].a)%=k;
		cnt=(cnt+k)%k;
	}
	printf("%lld\n",ans);
	return 0;
}