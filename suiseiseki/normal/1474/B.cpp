#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
bool np[Maxn+5];
int p[Maxn+5],p_len;
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			if(1ll*i*i>Maxn){
				continue;
			}
			for(int j=i*i;j<=Maxn;j+=i){
				np[j]=1;
			}
		}
	}
}
void solve(){
	int d;
	scanf("%d",&d);
	int t_1=lower_bound(p+1,p+1+p_len,d+1)-p;
	int t_2=lower_bound(p+1,p+1+p_len,p[t_1]+d)-p;
	printf("%lld\n",1ll*p[t_1]*p[t_2]);
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