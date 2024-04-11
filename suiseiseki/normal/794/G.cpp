#include <cstdio>
int abs(int a){
	return a<0?-a:a;
}
int max(int a,int b){
	return a>b?a:b;
}
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
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
const int Mod=1000000007;
const int Maxn=1000000;
int n;
int len_a,len_b;
char a[Maxn+5],b[Maxn+5];
int frac[Maxn<<1|5],inv_f[Maxn<<1|5];
bool np[Maxn+5];
int p[Maxn+5],p_len,mu[Maxn+5];
int pow_2[Maxn+5];
int f[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=(Maxn<<1);i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn<<1]=quick_power(frac[Maxn<<1],Mod-2,Mod);
	for(int i=(Maxn<<1)-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	np[0]=np[1]=1;
	mu[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			mu[i]=Mod-1;
		}
		for(int j=1,x;(x=i*p[j])<=Maxn;j++){
			np[x]=1;
			if(i%p[j]==0){
				mu[x]=0;
				break;
			}
			mu[x]=Mod-mu[i];
		}
	}
	pow_2[0]=1;
	for(int i=1;i<=Maxn+1;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
	for(int i=1;i<=Maxn;i++){
		for(int j=i;j<=Maxn;j+=i){
			f[j]=(f[j]+1ll*pow_2[i]*mu[j/i])%Mod;
		}
	}
	for(int i=1;i<=n;i++){
		int now=(n/i);
		now=1ll*now*now%Mod*f[i]%Mod;
		f[i]=(f[i-1]+now)%Mod;
	}
}
int C(int n,int m){
	if(n<m||m<0){
		return 0;
	}
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int calc(int n_a,int n_b){
	if(n_a==0&&n_b==0){
		return f[n];
	}
	if(n_a>=0&&n_b>=0){
		return 0;
	}
	if(n_a<=0&&n_b<=0){
		return 0;
	}
	n_a=abs(n_a),n_b=abs(n_b);
	if(n_a==n_b){
		return pow_2[n+1]-2;
	}
	int g=gcd(n_a,n_b);
	return pow_2[n/max(n_a/g,n_b/g)+1]-2;
}
int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	scanf("%d",&n);
	init();
	while(a[++len_a]!='\0');
	while(b[++len_b]!='\0');
	len_a--;
	len_b--;
	int num_a=0,num_b=0;
	int q_a=0,q_b=0;
	for(int i=1;i<=len_a;i++){
		if(a[i]=='?'){
			q_a++;
		}
		else if(a[i]=='A'){
			num_a++;
		}
		else{
			num_b++;
		}
	}
	for(int i=1;i<=len_b;i++){
		if(b[i]=='?'){
			q_b++;
		}
		else if(b[i]=='A'){
			num_a--;
		}
		else{
			num_b--;
		}
	}
	int ans=0;
	for(int i=-max(q_a,q_b);i<=max(q_a,q_b);i++){
		if(C(q_a+q_b,q_a-i)==0){
			continue;
		}
		ans=(ans+1ll*C(q_a+q_b,q_a-i)*calc(num_a+i,num_b+q_a-q_b-i))%Mod;
	}
	if(len_a==len_b){
		bool flag=1;
		for(int i=1;i<=len_a;i++){
			if(a[i]!=b[i]&&a[i]!='?'&&b[i]!='?'){
				flag=0;
				break;
			}
		}
		if(flag){
			int tmp=1;
			for(int i=1;i<=len_a;i++){
				if(a[i]=='?'&&b[i]=='?'){
					tmp=(tmp<<1)%Mod;
				}
			}
			ans=(ans-1ll*f[n]*tmp%Mod+Mod)%Mod;
			ans=(ans+1ll*(pow_2[n+1]-2)*(pow_2[n+1]-2)%Mod*tmp)%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}