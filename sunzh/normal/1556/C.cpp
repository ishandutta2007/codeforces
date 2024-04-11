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
int n;
int a[1010];
int main(){
	n=read();
	long long ans=0;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;i+=2){
		long long mx=0,cnt0=0,cnt1=0;
		for(int j=i+1;j<=n;++j){
			if(~j&1){
				// printf("i:%d,j:%d,%d %d\n",i,j,a[i]-max(1,mx)+1,a[j]-max(1,cnt0+mx-cnt1)+1);
				ans+=max(0ll,min(a[i]-max(1ll,mx)+1,a[j]-max(1ll,cnt0+mx-cnt1)+1));
				// printf("i:%d,j:%d,ans:%lld\n",i,j,ans);
			}
			if(mx>a[i]) break ;
			if(j&1) cnt0+=a[j];else cnt1+=a[j];
			mx=max(mx,cnt1-cnt0);
		}
	}
	printf("%lld\n",ans);
}