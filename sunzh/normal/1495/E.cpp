#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int m;
int t[5000010],a[5000010];
int ans[5000010];
signed main(){
	n=read();m=read();
	int lst=0;
	for(int i=1;i<=m;++i){
		int p=read(),k=read(),b=read(),w=read();
		int seed=b,base=w;
		auto rnd=[&](){
			int ret=seed;
			int mod=1000000007;
			seed=(1ll*seed*base%mod+233)%mod;
			return ret;
		};
		for(int j=lst+1;j<=p;++j){
			t[j]=(rnd()%2)+1;
			a[j]=(rnd()%k)+1;
		}
		lst=p;
	} 
	long long sum1,sum2;sum1=sum2=0;
	for(int i=1;i<=n;++i){
		if(t[i]==1) sum1+=a[i];
		else sum2+=a[i];
//		printf("a[%d]=%d\n",i,a[i]);
//		printf("t[%d]=%d\n",i,t[i]);
	}
	const int mod=1e9+7;
	if(sum1==sum2){
		int res=1;
		
		for(int i=1;i<=n;++i){
			res=1ll*res*(((ans[i]^(i*i))+1)%mod)%mod;
		}
		printf("%lld\n",res);
	}
	if(sum1<sum2){
		for(int i=1;i<=n;++i)if(t[i]==1) t[i]=0;else t[i]=1;
	}
//	for(int i=1;i<=n;++i) printf("t[%d]=%d\n",i,t[i]);
	int s=0;
	if(t[1]!=1){
		s=1;
	}
	else{
		ans[1]=1;--a[1];
		s=0;
		for(int i=1;i<=n;++i)
		if(t[i]!=1){
			s=i;break ;
		}
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		int p=(s+i-2)%n+1;
		if(t[p]!=1){
			sum+=a[p];
		}
		else{
//			printf("i:%d,p:%d,sum:%d\n",i,p,sum);
			if(sum>a[p]){
				ans[p]+=a[p];sum-=a[p];a[p]=0;
			}
			else {
				ans[p]+=sum;a[p]-=sum;sum=0;
			}
		}
	}
	for(int i=1;i<=n;++i){
		int p=(s+i-1)%n+1;
		if(t[p]==1){
			if(sum>a[p]) {
				ans[p]+=a[p],sum-=a[p];a[p]=0;
			}
			else{
				ans[p]+=sum;break ;
			}
		}
	}
	int res=1;
	
	for(int i=1;i<=n;++i){
		if(t[i]!=1) ans[i]=a[i];
//		if(ans[i]<0) printf("ans[%d]=%d\n",i,ans[i]);
		res=1ll*res*(((ans[i]^(1ll*i*i))+1)%mod)%mod;
	}
	printf("%lld\n",res);
}