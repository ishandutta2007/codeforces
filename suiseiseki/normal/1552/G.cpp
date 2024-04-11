#include <cstdio>
typedef long long ll;
const int Maxn=40;
const int Maxk=10;
int n,k;
int q[Maxk+5];
ll mask[Maxk+5][Maxn+5];
ll vis_val[Maxk+5],active[Maxk+5];
int in_active[Maxk+5];
bool work_dfs(ll s,int t){
	if(t==k-1){
		int num_one=__builtin_popcountll(s);
		int num_zero=n-num_one;
		ll s_1=((1ll<<num_one)-1)<<num_zero;
		ll s_2=(s^s_1);
		return (s_2&vis_val[t])==s_2;
	}
	int min_ones=__builtin_popcountll(s&vis_val[t]);
	s|=vis_val[t];
	for(int i=min_ones;i<=min_ones+in_active[t];i++){
		if(!work_dfs(s&mask[t][i],t+1)){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&k);
	if(n==1){
		puts("ACCEPTED");
		return 0;
	}
	for(int t=0;t<k;t++){
		scanf("%d",&q[t]);
		mask[t][q[t]]=(1ll<<n)-1;
		for(int i=0;i<q[t];i++){
			int x;
			scanf("%d",&x);
			x--;
			vis_val[t]|=(1ll<<x);
			mask[t][q[t]-(i+1)]=~vis_val[t];
		}
		in_active[t]=__builtin_popcountll(vis_val[t]&(~active[t]));
		active[t+1]=active[t]|vis_val[t];
	}
	if(q[k-1]==n){
		puts("ACCEPTED");
		return 0;
	}
	if(active[k-1]!=(1ll<<n)-1){
		puts("REJECTED");
		return 0;
	}
	if(work_dfs(0,0)){
		puts("ACCEPTED");
	}
	else{
		puts("REJECTED");
	}
	return 0;
}