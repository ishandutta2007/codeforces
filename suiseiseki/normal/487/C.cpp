#include <cstdio>
#define Maxn 100000
bool prime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
int ans[Maxn+5];
int ksm(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=(int)(1ll*ans*a%Mod);
		}
		b>>=1;
		a=(int)(1ll*a*a%Mod);
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("YES");
		puts("1");
		return 0;
	}
	if(n==4){
		puts("YES");
		printf("1\n3\n2\n4\n");
		return 0;
	}
	if(prime(n)){
		puts("YES");
		ans[1]=1;
		ans[n]=n;
		for(int i=2;i<n;i++){
			ans[i]=(int)(1ll*i*ksm(i-1,n-2,n)%n);
		}
		for(int i=1;i<=n;i++){
			printf("%d\n",ans[i]);
		}
	}
	else{
		puts("NO");
	}
	return 0;
}