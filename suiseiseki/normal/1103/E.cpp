#include <cstdio>
const int Maxn=100000;
typedef unsigned long long ull;
const int pow_10[7]={1,10,100,1000,10000,100000,1000000};
const ull inv_5=14757395258967641293ull;
const ull Mod=(1ull<<58);
int n;
struct Vector{
	ull a[5];
	Vector(){
		a[0]=a[1]=a[2]=a[3]=a[4]=0;
	}
	friend Vector operator +(const Vector &a,const Vector &b){
		Vector ans;
		for(int i=0;i<5;i++){
			ans.a[i]=a.a[i]+b.a[i];
		}
		return ans;
	}
	friend Vector operator -(const Vector &a,const Vector &b){
		Vector ans;
		for(int i=0;i<5;i++){
			ans.a[i]=a.a[i]-b.a[i];
		}
		return ans;
	}
	friend Vector operator *(const Vector &a,const ull &b){
		Vector ans;
		for(int i=0;i<5;i++){
			ans.a[i]=a.a[i]*b;
		}
		return ans;
	}
	friend Vector operator *(const Vector &a,const Vector &b){
		static ull tmp[9];
		for(int i=0;i<9;i++){
			tmp[i]=0;
		}
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				tmp[i+j]+=a.a[i]*b.a[j];
			}
		}
		for(int i=0;i<4;i++){
			tmp[i]+=tmp[i+5];
		}
		Vector ans;
		for(int i=0;i<5;i++){
			ans.a[i]=tmp[i];
		}
		return ans;
	}
}w_10[10],a[Maxn+5];
void init(){
	w_10[0].a[0]=1,w_10[1].a[3]=-1;
	for(int i=2;i<10;i++){
		w_10[i]=w_10[i-1]*w_10[1];
	}
}
void FFT(Vector *a,int flag,int len){
	for(int mid=0;mid<5;mid++){
		for(int i=0;i<len;i++){
			if((i/pow_10[mid])%10==0){
				Vector tmp[10];
				for(int j=0;j<10;j++){
					for(int k=0;k<10;k++){
						tmp[j]=tmp[j]+a[i+k*pow_10[mid]]*w_10[(flag*j*k%10+10)%10];
					}
				}
				for(int j=0;j<10;j++){
					a[i+j*pow_10[mid]]=tmp[j];
				}
			}
		}
	}
	if(flag==-1){
		ull inv=inv_5*inv_5*inv_5*inv_5*inv_5;
		for(int i=0;i<len;i++){
			a[i]=a[i]*inv;
		}
	}
}
Vector quick_power(Vector a,int b){
	Vector ans=w_10[0];
	while(b){
		if(b&1){
			ans=ans*a;
		}
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[x].a[0]++;
	}
	FFT(a,1,Maxn);
	for(int i=0;i<Maxn;i++){
		a[i]=quick_power(a[i],n);
	}
	FFT(a,-1,Maxn);
	for(int i=0;i<n;i++){
		printf("%llu\n",((a[i].a[0]-a[i].a[4])/32)%Mod);
	}
	return 0;
}