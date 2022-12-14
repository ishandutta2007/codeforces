#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m,p,a[N],t,d[N],tot,q[N],nq,dp[N];
int pw(int a,int x,int p){int ans=1;for(;x;x>>=1,a=1ll*a*a%p)if(x&1)ans=1ll*ans*a%p;return ans;}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	t=p-1;
	for(int i=1,b;i<=m;i++){
		scanf("%d",&b);
		t=__gcd(t,b);
	}
	for(int x=1;x*x<=p-1;x++)
		if((p-1)%x==0){
			d[tot++]=x;
			if(x!=(p-1)/x)d[tot++]=(p-1)/x;
		}
	sort(d,d+tot);
	for(int i=1;i<=n;i++)
		for(int j=0;j<tot;j++)
			if(pw(a[i],d[j],p)==1){
				q[i]=__gcd(int((p-1ll)/d[j]*t%(p-1)),p-1);
				break;
			}
	sort(q+1,q+1+n);
	nq=unique(q+1,q+1+n)-q-1;
	int ans=0;
	for(int i=nq;i;i--){
		dp[i]=(p-1)/q[i];
		for(int j=i+1;j<=nq;j++)
			if(q[j]%q[i]==0)dp[i]-=dp[j];
		ans+=dp[i];
	}
	printf("%d\n",ans);
	return 0;
}