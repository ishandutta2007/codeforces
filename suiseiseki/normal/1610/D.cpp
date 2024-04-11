#include <cstdio>
const int Maxn=200000;
const int Mod=1000000007;
int n;
int a[Maxn+5];
int pow_2[Maxn+5];
void divide_2(){
	int m=0;
	for(int i=1;i<=n;i++){
		if(a[i]%2==0){
			a[++m]=a[i]/2;
		}
	}
	n=m;
}
int find_num(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]&1){
			ans++;
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	pow_2[0]=1;
	for(int i=1;i<=n;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
	int ans=0;
	int val=find_num();
	ans=(ans+1ll*(pow_2[val]-1+Mod)*pow_2[n-val])%Mod;
	divide_2();
	while(n>0){
		int val=find_num();
		if(val==0){
			divide_2();
			continue;
		}
		ans=(ans+1ll*(pow_2[val-1]-1+Mod)*pow_2[n-val])%Mod;
		divide_2();
	}
	printf("%d\n",ans);
	return 0;
}