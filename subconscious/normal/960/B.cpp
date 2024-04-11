#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define P 1000000007
#define N 1005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef long double ld;
int a[N],b[N],n,k1,k2;
ll ans;
int main(){
	ans=0;
	scanf("%d%d%d",&n,&k1,&k2);
	rep(i,n)scanf("%d",a+i);
	rep(i,n)scanf("%d",b+i);
	rep(i,n)a[i]=abs(a[i]-b[i]);
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	int now=1,cnt=1;
	for(;cnt<=k1+k2;++cnt){
		while(a[now]==a[now+1]&&now<=n)++now;
		if(now>n){--cnt;break;}
		--a[now];if(now>1)--now;
		//printf("%d\n",now);
		//rep(i,n)printf("%d%c",a[i],i==n?'\n':' ');
	}
	if((k1+k2-cnt)%2==1)++a[1];
	rep(i,n)ans+=1ll*a[i]*a[i];
	printf("%lld\n",ans);
	return 0;
}