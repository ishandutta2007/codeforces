#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
typedef long long ll;
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
const int Maxn=1000000;
int n;
std::mt19937 rnd(time(NULL));
ll a[Maxn+5],b[Maxn+5];
ll d[Maxn+5],d_len;
int val[Maxn+5];
void factor(ll v){
	d_len=0;
	for(int i=1;1ll*i*i<=v;i++){
		if(v%i==0){
			d[++d_len]=i;
			if(1ll*i*i<v){
				d[++d_len]=v/i;
			}
		}
	}
	std::sort(d+1,d+1+d_len);
	for(int i=1;i<=d_len;i++){
		val[i]=0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll ans=1;
	for(int t=0;t<12;t++){
		int id=rnd()%n+1;
		factor(a[id]);
		for(int i=1;i<=n;i++){
			b[i]=gcd(a[id],a[i]);
			int pos=std::lower_bound(d+1,d+1+d_len,b[i])-d;
			val[pos]++;
		}
		for(int i=1;i<=d_len;i++){
			for(int j=i+1;j<=d_len;j++){
				if(d[j]%d[i]==0){
					val[i]+=val[j];
				}
			}
		}
		for(int i=1;i<=d_len;i++){
			if(val[i]>=((n+1)>>1)){
				ans=std::max(ans,d[i]);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}