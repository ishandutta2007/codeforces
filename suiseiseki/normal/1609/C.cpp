#include <cstdio>
typedef long long ll;
const int Maxn=200000;
const int Maxv=1000000;
bool np[Maxv+5];
void init(){
	np[0]=np[1]=1;
	for(int i=2;i*i<=Maxv;i++){
		if(!np[i]){
			for(int j=i*i;j<=Maxv;j+=i){
				np[j]=1;
			}
		}
	}
}
int n,e;
int a[Maxn+5];
int lis[Maxn+5];
int m;
ll work(){
	ll ans=0;
	int pos_1=m+1,pos_2=m;
	for(int i=m;i>0;i--){
		if(lis[i]==-1){
			pos_1=i,pos_2=i-1;
		}
		else if(lis[i]==0){
			pos_2=pos_1-1;
			pos_1=i;
			ans+=pos_2-pos_1;
		}
		else{
			ans+=pos_2-pos_1+1;
		}
	}
	return ans;
}
void solve(){
	scanf("%d%d",&n,&e);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){
			continue;
		}
		if(np[a[i]]){
			a[i]=-1;
		}
		else{
			a[i]=0;
		}
	}
	ll ans=0;
	for(int i=1;i<=e;i++){
		m=0;
		for(int j=i;j<=n;j+=e){
			lis[++m]=a[j];
		}
		ans+=work();
	}
	printf("%lld\n",ans);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}