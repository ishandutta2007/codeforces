#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int x[10],y[10];
int tmp_x[10],tmp_y[10];
int id[10];
ll ans;
void solve(int u){
	for(int i=0;i<4;i++){
		tmp_x[i]=x[id[i]];
		if(i<2){
			tmp_x[i]+=u;
		}
		tmp_y[i]=y[id[i]];
		if(i&1){
			tmp_y[i]+=u;
		}
	}
	sort(tmp_x,tmp_x+4);
	sort(tmp_y,tmp_y+4);
	ll sum=0;
	for(int i=0;i<4;i++){
		sum+=0ll+abs(tmp_x[i]-tmp_x[1])+abs(tmp_y[i]-tmp_y[1]);
	}
	ans=min(ans,sum);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<4;i++){
			scanf("%d%d",&x[i],&y[i]);
			id[i]=i;
		}
		ans=Inf;
		do{
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					solve(x[id[i]]-x[id[j]]);
					solve(y[id[i]]-y[id[j]]);
				}
			}
		}while(next_permutation(id,id+4));
		printf("%lld\n",ans);
	}
	return 0;
}