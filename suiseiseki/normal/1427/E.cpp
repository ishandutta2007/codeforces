#include <cstdio>
typedef long long ll;
const int Maxn=100000;
int x;
struct Answer{
	int op;
	ll a,b;
}ans[Maxn+5];
int len;
bool vis[60];
void work(int x){
	if(x==1){
		return;
	}
	int high;
	for(int i=19;i>=0;i--){
		if((x>>i)&1){
			high=i;
			break;
		}
	}
	ll tmp=x;
	for(int i=0;i<high;i++){
		ans[++len].op=0;
		ans[len].a=tmp;
		ans[len].b=tmp;
		tmp<<=1;
	}
	if(!vis[high+1]){
		ans[++len].op=1;
		ans[len].a=tmp;
		ans[len].b=x;
		ll now=tmp^x;
		ans[++len].op=0;
		ans[len].a=now;
		ans[len].b=tmp;
		ll sum=now+tmp;
		ans[++len].op=1;
		ans[len].a=sum;
		ans[len].b=x;
		sum^=x;
		ans[++len].op=0;
		ans[len].a=tmp;
		ans[len].b=tmp;
		now=(tmp<<1);
		ans[++len].op=1;
		ans[len].a=now;
		ans[len].b=sum;
		vis[high+1]=1;
	}
	for(int i=high+1;(1ll<<i)<=tmp;i++){
		if(!vis[i]){
			ans[++len].op=0;
			ans[len].a=(1ll<<(i-1));
			ans[len].b=(1ll<<(i-1));
			vis[i]=1;
		}
		if((tmp>>i)&1){
			ans[++len].op=1;
			ans[len].a=tmp;
			ans[len].b=(1ll<<i);
			tmp^=(1ll<<i);
		}
	}
	vis[high]=1;
	ans[++len].op=1;
	ans[len].a=x;
	ans[len].b=(1ll<<high);
	x^=(1ll<<high);
	work(x);
}
int main(){
	scanf("%d",&x);
	work(x);
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		if(ans[i].op==0){
			printf("%lld + %lld\n",ans[i].a,ans[i].b);
		}
		else{
			printf("%lld ^ %lld\n",ans[i].a,ans[i].b);
		}
	}
	return 0;
}