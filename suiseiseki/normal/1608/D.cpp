#include <cstdio>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=200000;
const int Mod=998244353;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n;
int fac[Maxn+5],inv_f[Maxn+5];
void init(){
	fac[0]=1;
	for(int i=1;i<=Maxn;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxn]=find_inv(fac[Maxn]);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	if(m<0||n<m){
		return 0;
	}
	return 1ll*fac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	init();
	scanf("%d",&n);
	int add_1=1,add_2=1,y=n;
	int ans=0;
	int cnt_1=0,cnt_2=0,cnt_3=0;
	int sum=1;
	for(int i=1;i<=n;i++){
		static char s[5];
		scanf("%s",s);
		int num=0;
		if(s[0]=='?'&&s[1]=='?'){
			cnt_1++;
		}
		else if((s[0]=='W'&&s[1]=='?')||(s[0]=='?'&&s[1]=='W')){
			cnt_2++;
		}
		else if((s[0]=='?'&&s[1]=='B')||(s[0]=='B'&&s[1]=='?')){
			cnt_3++;
			y--;
		}
		else if(s[0]=='B'&&s[1]=='B'){
			y-=2;
		}
		else if((s[0]=='W'&&s[1]=='B')||(s[0]=='B'&&s[1]=='W')){
			y--;
		}
		if((s[0]=='?'||s[0]=='W')&&(s[1]=='?'||s[1]=='B')){
			num++;
		}
		else{
			add_1=0;
		}
		if((s[0]=='?'||s[0]=='B')&&(s[1]=='?'||s[1]=='W')){
			num++;
		}
		else{
			add_2=0;
		}
		sum=1ll*num*sum%Mod;
	}
	int x=cnt_1*2+cnt_2+cnt_3;
	ans=(0ll+ans-sum+Mod+C(x,y)+add_1+add_2)%Mod;
	printf("%d\n",ans);
	return 0;
}