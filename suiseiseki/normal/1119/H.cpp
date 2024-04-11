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
const int Maxn=100000;
const int Maxk=17;
const int Mod=998244353;
const int inv_2=(Mod+1)>>1;
int n,k;
int x,y,z;
int f_1[1<<Maxk|5],f_2[1<<Maxk|5],f_3[1<<Maxk|5];
int f[1<<Maxk|5];
void FWT_xor(int *a,int flag,int len){
	for(int j=1;j<len;j<<=1){
		for(int k=0;k<len;k+=(j<<1)){
			for(int l=0;l<j;l++){
				int Nx=a[k+l],Ny=a[j+k+l];
				a[k+l]=(Nx+Ny)%Mod;
				a[j+k+l]=(Nx-Ny+Mod)%Mod;
				if(flag==-1){
					a[k+l]=1ll*a[k+l]*inv_2%Mod;
					a[j+k+l]=1ll*a[j+k+l]*inv_2%Mod;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%d%d%d",&x,&y,&z);
	int sum_a=0;
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		b^=a;
		c^=a;
		sum_a^=a;
		a^=a;
		f_1[b]++;
		f_2[c]++;
		f_3[b^c]++;
	}
	int s_1,s_2,s_3,s_4;
	s_1=(0ll+x+y+z)%Mod;
	s_2=(0ll+x+y-z+Mod)%Mod;
	s_3=(0ll+x-y+z+Mod)%Mod;
	s_4=(0ll+x-y-z+Mod+Mod)%Mod;
	FWT_xor(f_1,1,1<<k);
	FWT_xor(f_2,1,1<<k);
	FWT_xor(f_3,1,1<<k);
	for(int i=0;i<(1<<k);i++){
		int c_1=(0ll+n+f_1[i]+f_2[i]+f_3[i])*inv_2%Mod*inv_2%Mod;
		int c_2=(0ll+n+f_1[i]-c_1-c_1)*inv_2%Mod;
		if(c_2<0){
			c_2+=Mod;
		}
		int c_3=(0ll+n+f_2[i]-c_1-c_1)*inv_2%Mod;
		if(c_3<0){
			c_3+=Mod;
		}
		int c_4=(0ll+n+f_3[i]-c_1-c_1)*inv_2%Mod;
		if(c_3<0){
			c_3+=Mod;
		}
		f[i]=1ll*quick_power(s_1,c_1,Mod)*quick_power(s_2,c_2,Mod)%Mod*quick_power(s_3,c_3,Mod)%Mod*quick_power(s_4,c_4,Mod)%Mod;
	}
	FWT_xor(f,-1,1<<k);
	for(int i=0;i<(1<<k);i++){
		printf("%d ",f[i^sum_a]);
	}
	puts("");
	return 0;
}