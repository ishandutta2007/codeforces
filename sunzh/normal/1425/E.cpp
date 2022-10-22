#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
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
int n,k;
int a[100010],d[100010];
int presum[100010];
int sufsum[100010];
int maxn[100010];
int minn[100010];
signed main(){
	int ans=0;
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) d[i]=read();
	if(k==0){
		for(int i=n;i>=1;--i) sufsum[i]=sufsum[i+1]+a[i],ans=max(ans,sufsum[i]-d[i]);
	}
	else if(k==1){
		for(int i=n;i>=2;--i) sufsum[i]=sufsum[i+1]+a[i],ans=max(ans,sufsum[i]-d[i]),maxn[i]=max(maxn[i+1],sufsum[i]-d[i]);
		minn[0]=0x3f3f3f3f;
		for(int i=1;i<n;++i){
			presum[i]=presum[i-1]+a[i];
			minn[i]=min(minn[i-1],d[i]);
			ans=max(ans,presum[i]-minn[i]);
			ans=max(ans,presum[i]-minn[i]+maxn[i+1]);
		}
		int sum=sufsum[2]+a[1];
		for(int i=2;i<=n;++i) ans=max(ans,sum-d[1]-min(a[i],d[i]));
	}
	else{
		for(int i=1;i<=n;++i) presum[i]=presum[i-1]+a[i];
		for(int i=1;i<n;++i) ans=max(ans,presum[n]-d[i]);
		ans=max(ans,a[n]-d[n]);
	}
	printf("%lld\n",ans);
	return 0;
}