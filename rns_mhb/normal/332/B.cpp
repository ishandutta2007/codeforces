#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;
typedef __int64 ll;
#define M 200010
#define Max(a,b) ((a)<(b)? (b):(a))
ll s[M],x[M],ss[M],mx[M];
int num[M];
int main(){
	//freopen("in.in","r",stdin);
	ll n,k;
	int i,j;

	scanf("%I64d %I64d\n",&n,&k);
	memset(s,0,sizeof(s));
	for (i=1;i<=n;i++) scanf("%I64d",x+i),s[i]=s[i-1]+x[i];
	for (i=1;i<=n-k+1;i++) ss[i]=s[i+k-1]-s[i-1];
	int a=0,b=n-k+1;
	memset(mx,0,sizeof(mx));
	memset(num,0,sizeof (num));
	mx[n-k+1]=ss[n-k+1];
	num[n-k+1]=n-k+1;
	for (i=n-k;i>=1;i--){
		mx[i]=Max(mx[i+1],ss[i]);
		if (mx[i]==ss[i]) num[i]=i;
		else num[i]=num[i+1];
	}
	ll sum=0,pre;

	for (i=1;i<=n-k-k+1;i++){
		//printf("%d %I64d %I64d\n",i,ss[i],mx[i+k]);
		pre=ss[i]+mx[i+k];
		if (sum<pre){
			a=i;b=num[i+k];
			sum=pre;
		}
	}
	printf("%d %d\n",a,b);
	return 0;
}