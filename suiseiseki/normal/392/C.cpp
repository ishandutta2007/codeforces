#include <cstdio>
typedef long long ll;
const int Maxk=40;
const int Mod=1000000007;
int C[Maxk+5][Maxk+5];
ll n;
int k;
void init(){
	C[0][0]=1;
	for(int i=1;i<=Maxk;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
}
struct Matrix{
	int a[2][2];
	void init(){
		a[0][0]=a[1][1]=1;
		a[0][1]=a[1][0]=0;
	}
	void clear(){
		a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
	}
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix ans;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				ans.a[i][j]=0;
				for(int k=0;k<2;k++){
					ans.a[i][j]=(ans.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%Mod;
				}
			}
		}
		return ans;
	}
	friend Matrix operator +(Matrix a,Matrix b){
		Matrix ans;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				ans.a[i][j]=(a.a[i][j]+b.a[i][j])%Mod;
			}
		}
		return ans;
	}
	friend Matrix operator *(Matrix a,int b){
		Matrix ans;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				ans.a[i][j]=1ll*a.a[i][j]*b%Mod;
			}
		}
		return ans;
	}
}fib,f[Maxk+5],t[Maxk+5],tmp;
int pow_m[Maxk+5];
void solve(ll n){
	if(n==1){
		for(int i=0;i<=k;i++){
			f[i]=fib;
		}
		tmp=fib;
		return;
	}
	ll m=(n>>1);
	solve(m);
	for(int i=0;i<=k;i++){
		t[i]=f[i];
		f[i].clear();
	}
	pow_m[0]=1;
	for(int i=1,tmp_m=m%Mod;i<=k;i++){
		pow_m[i]=1ll*pow_m[i-1]*tmp_m%Mod;
	}
	for(int i=0;i<=k;i++){
		for(int j=0;j<=i;j++){
			f[i]=f[i]+t[j]*(1ll*C[i][j]*pow_m[i-j]%Mod);
		}
		f[i]=f[i]*tmp;
	}
	for(int i=0;i<=k;i++){
		f[i]=f[i]+t[i];
	}
	tmp=tmp*tmp;
	if(n&1){
		tmp=tmp*fib;
		pow_m[0]=1;
		for(int i=1,tmp_m=n%Mod;i<=k;i++){
			pow_m[i]=1ll*pow_m[i-1]*tmp_m%Mod;
		}
		for(int i=0;i<=k;i++){
			f[i]=f[i]+tmp*pow_m[i];
		}
	}
}
int main(){
	fib.a[0][0]=fib.a[0][1]=fib.a[1][0]=1;
	fib.a[1][1]=0;
	scanf("%lld%d",&n,&k);
	init();
	solve(n);
	printf("%d\n",f[k].a[0][0]);
	return 0;
}