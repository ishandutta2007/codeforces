#include <cstdio>
const int Maxn=100000;
int n,k,Mod;
int sum[Maxn+5];
int inv[Maxn+5];
void init(){
	inv[1]=1;
	for(int i=2;i<=Maxn;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
	for(int i=1;i<=Maxn;i++){
		sum[i]=(sum[i-1]+inv[i])%Mod;
	}
}
int cnt[Maxn+5];
void merge_sort(int l,int r,int k){
	if(k==1||l==r){
		cnt[r-l+1]++;
		return;
	}
	int mid=(l+r)>>1;
	merge_sort(l,mid,k-1);
	merge_sort(mid+1,r,k-1);
}
int calc(int len_1,int len_2){
	int ans=0;
	for(int i=1;i<=len_1;i++){
		ans=(ans+1ll*len_2*inv[2])%Mod;
		int now=(sum[i+len_2]-sum[i]+Mod)%Mod;
		ans=(ans-now+Mod)%Mod;
	}
	return ans;
}
int lis[Maxn+5],lis_len;
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]){
			lis[++lis_len]=i;
			ans=(ans+1ll*cnt[i]*i*(i-1)%Mod*inv[4])%Mod;
			if(cnt[i]>1){
				ans=(ans+1ll*cnt[i]*(cnt[i]-1)%Mod*inv[2]%Mod*calc(i,i))%Mod;
			}
		}
	}
	for(int i=1;i<=lis_len;i++){
		for(int j=i+1;j<=lis_len;j++){
			ans=(ans+1ll*cnt[lis[i]]*cnt[lis[j]]%Mod*calc(lis[i],lis[j]))%Mod;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&k,&Mod);
	init();
	merge_sort(1,n,k);
	printf("%d\n",solve());
	return 0;
}