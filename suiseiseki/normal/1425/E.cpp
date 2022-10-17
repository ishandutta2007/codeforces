#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=100000;
int n,k;
int a[Maxn+5];
int d[Maxn+5];
ll f[Maxn+5],s[Maxn+5];
int minn[Maxn+5],g[Maxn+5];
int main(){
	scanf("%d%d",&n,&k);
	int pos=-1,nxt=-1;
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if(pos==-1||d[i]<d[pos]){
			nxt=pos;
			pos=i;
		}
		else if(nxt==-1||d[i]<d[pos]){
			nxt=i;
		}
	}
	if(k>=2){
		if(pos==n){
			printf("%lld\n",max(0ll,max(1ll*a[n]-d[n],sum-d[nxt])));
		}
		else{
			printf("%lld\n",max(0ll,sum-d[pos]));
		}
		return 0;
	}
	for(int i=n;i>0;i--){
		s[i]=s[i+1]+a[i];
		f[i]=max(f[i+1],s[i]-d[i]);
	}
	if(k==0){
		printf("%lld\n",f[1]);
		return 0;
	}
	minn[1]=d[1];
	for(int i=2;i<=n;i++){
		minn[i]=min(minn[i-1],d[i]);
	}
	ll S=0;
	ll ans=0;
	S=a[1];
	for(int i=2;i<n;i++){
		S+=a[i];
		ans=max(ans,max(0ll,S-minn[i])+f[i+1]);
	}
	int tmp=a[2];
	for(int i=3;i<=n;i++){
		tmp=min(tmp,a[i]);
	}
	ans=max(ans,sum-tmp-d[1]);
	ans=max(ans,f[2]);
	ans=max(ans,sum-d[1]-d[2]);
	printf("%lld\n",ans);
	return 0;
}