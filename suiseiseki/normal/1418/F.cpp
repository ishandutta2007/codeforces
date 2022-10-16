#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200000;
int n,m;
ll l,r;
vector<int> p[Maxn+5];
void init(){
	for(int i=1;i<=Maxn;i++){
		for(int j=i;j<=Maxn;j+=i){
			p[j].push_back(i);
		}
	}
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	scanf("%lld%lld",&l,&r);
	ll ans=0;
	for(int x=1;x<=n;x++){
		bool flag=0;
		ll left=max(1ll,(l-1)/x+1),right=min(1ll*m,r/x);
		for(int d:p[x]){
			int a=x/d;
			if(left>right){
				continue;
			}
			for(int k=d+1,nxt;k<=n/a&&k<=m;k=nxt+1){
				if((left-1)/k==0){
					if(right/k==0){
						break;
					}
					nxt=min(1ll*n/a,right/(right/k));
				}
				else{
					nxt=min(1ll*n/a,min((left-1)/((left-1)/k),right/(right/k)));
				}
				ll l_b=(left-1)/k+1,r_b=right/k;
				if(l_b>r_b){
					continue;
				}
				flag=1;
				printf("%d %lld %lld %lld\n",x,l_b*k,1ll*a*k,l_b*d);
				break;
			}
			if(flag){
				break;
			}
		}
		if(!flag){
			puts("-1");
			continue;
		}
	}
	return 0;
}