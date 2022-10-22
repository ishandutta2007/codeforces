#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int T;
int n;
long long pre[200010],jmp[200010];
int a[200010];
int main(){
	T=read();
	for(int i=1;i<=T;++i){
		n=read();
//		if(i==36) printf("n:%d\n",n);
		for(int i=1;i<=n;++i) a[i]=read(),pre[i]=pre[i-1]+a[i];jmp[1]=a[1];
//		printf("%lld\n",pre[n]); 
//		if(i==36)for(int i=1;i<=n;++i){
//			printf("%d ",a[i]);
//		}
		for(int i=2;i<=n;++i) jmp[i]=jmp[i-2]+a[i];
		int l=1,r=n,rs=0;
		long long ans=0;
		//PCCCCCPCPCPCPCPPPP
		//PCCCCCPCPCPCPCPPPC
		//CCCCCCPCPCPCPCPPPP
		//CCCCCCPCPCPCPCPPPC
		//PPPPPPCCCCCCCCC
		for(int i=1;i<=n;++i){
			if(pre[i]>pre[n]-pre[i]){
//				printf("i:%d\n",i);
				++ans;
			}
			int l=0,r=(n-i>>1),rs=-1;
			while(l<=r){
				int mid=l+r>>1;
				int t=i+(mid<<1);
				if(jmp[t]-jmp[i]+pre[i]<pre[n]-pre[i]-jmp[t]+jmp[i]){
					rs=mid;l=mid+1;
				}
				else r=mid-1;
			}
			ans+=rs+1;
			l=0,r=(n-i-3>>1),rs=-1;
			while(l<=r){
				int mid=l+r>>1;
				int t=i+(mid<<1);
				if(jmp[t]-jmp[i]+pre[i]+a[n]<pre[n]-a[n]-pre[i]-jmp[t]+jmp[i]){
					rs=mid;l=mid+1;
				}
				else r=mid-1;
			}
			ans+=rs+1;
//			printf("%d\n",ans);
			if(i>1&&i<n){
				l=0,r=(n-i>>1),rs=-1;
				while(l<=r){
					int mid=l+r>>1;
					int t=i+(mid<<1);
					if(jmp[t]-jmp[i]+pre[i]-a[1]<a[1]+pre[n]-pre[i]-jmp[t]+jmp[i]){
						rs=mid;l=mid+1;
					}
					else r=mid-1;
				}
				ans+=rs+1;
//				if(n-i-3<0) continue ;
				l=0,r=(n-i-3>>1),rs=-1;
				while(l<=r){
					int mid=l+r>>1;
					int t=i+(mid<<1);
					if(jmp[t]-jmp[i]+pre[i]-a[1]+a[n]<-a[n]+a[1]+pre[n]-pre[i]-jmp[t]+jmp[i]){
						rs=mid;l=mid+1;
					}
					else r=mid-1;
				}
				ans+=rs+1;
			}
//			printf("i:%d,%lld\n",i,ans);
		}
		printf("%d\n",ans%998244353);
	}
}