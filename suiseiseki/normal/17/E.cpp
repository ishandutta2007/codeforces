#include <cstdio>
#define Maxn 4000000
#define Mod 51123987
char a[Maxn+5],b[Maxn+5];
int f[Maxn+5],l[Maxn+5],r[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",a);
	int len=1;
	b[0]=1;
	for(int i=0;i<n;i++,len++){
		b[++len]=a[i];
	}
	int maxn=0,id=1;
	for(int i=1;i<=len;i++){
		if(i<maxn){
			f[i]=mn(maxn-i,f[(id<<1)-i]);
		}
		else{
			f[i]=1;
		}
		while(b[i-f[i]]==b[i+f[i]]){
			f[i]++;
		}
		if(i+f[i]>maxn){
			maxn=i+f[i];
			id=i;
		}
	}
	int ans=0;
	for(int i=1;i<=len;i++){
		l[i-f[i]+1]++;
		l[i+1]--;
		r[i]++;
		r[i+f[i]]--;
		ans+=(f[i]>>1);
		ans%=Mod;
	}
	ans=(int)(((long long)ans*(ans-1)>>1)%Mod);
	int s=0;
	for(int i=1;i<=len;i++){
		l[i]+=l[i-1];
		r[i]+=r[i-1];
		if(!(i&1)){
			ans-=(int)((long long)s*l[i]%Mod);
			ans%=Mod;
			s=(int)(((long long)s+r[i])%Mod);
		}
	}
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}