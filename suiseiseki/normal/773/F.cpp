#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=120000;
int n,m,p;
namespace Poly{
	typedef long double ld;
	const ld PI=acos(-1.0);
	struct Complex{
		ld r,i;
		Complex(ld _r=0,ld _i=0){
			r=_r;
			i=_i;
		}
		Complex conj(){
			return Complex(r,-i);
		}
		friend Complex operator +(Complex a,Complex b){
			return Complex(a.r+b.r,a.i+b.i);
		}
		friend Complex operator -(Complex a,Complex b){
			return Complex(a.r-b.r,a.i-b.i);
		}
		friend Complex operator *(Complex a,Complex b){
			return Complex(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
		}
		Complex operator /=(int n){
			r/=n;
			i/=n;
			return (*this);
		}
	};
	typedef long long ll;
	Complex a[Maxn+5],b[Maxn+5],c[Maxn+5],d[Maxn+5];
	void FFT(Complex *a,int flag,int n){
		static int R[Maxn+5],last_len=0;
		int len=1,L=0;
		while(len<n){
			len<<=1;
			L++;
		}
		if(len!=last_len){
			last_len=len;
			for(int i=0;i<len;i++){
				R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
			}
		}
		for(int i=0;i<len;i++){
			if(i<R[i]){
				swap(a[i],a[R[i]]);
			}
		}
		for(int j=1;j<len;j<<=1){
			Complex T=Complex(cos(PI/j),flag*sin(PI/j));
			for(int k=0;k<len;k+=(j<<1)){
				Complex t=Complex(1,0);
				for(int l=0;l<j;l++,t=t*T){
					Complex Nx=a[k+l],Ny=t*a[j+k+l];
					a[k+l]=Nx+Ny;
					a[j+k+l]=Nx-Ny;
				}
			}
		}
		if(flag==-1){
			for(int i=0;i<len;i++){
				a[i]/=len;
			}
		}
	}
	void MTT(int *f,int *g,int *h,int n,int p){
		for(int i=0;i<n;i++){
			a[i].r=(f[i]>>15),a[i].i=(f[i]&32767);
			c[i].r=(g[i]>>15),c[i].i=(g[i]&32767);
		}
		FFT(a,1,n);
		FFT(c,1,n);
		b[0]=a[0].conj();
		for(int i=1;i<n;i++){
			b[i]=a[n-i].conj();
		}
		d[0]=c[0].conj();
		for(int i=1;i<n;i++){
			d[i]=c[n-i].conj();
		}
		for(int i=0;i<n;i++){
			Complex tmp_a=(a[i]+b[i])*Complex(0.5,0),
			tmp_b=(a[i]-b[i])*Complex(0,-0.5),
			tmp_c=(c[i]+d[i])*Complex(0.5,0),
			tmp_d=(c[i]-d[i])*Complex(0,-0.5);
			a[i]=tmp_a*tmp_c+Complex(0,1)*(tmp_a*tmp_d+tmp_b*tmp_c);
			b[i]=tmp_b*tmp_d;
		}
		FFT(a,-1,n);
		FFT(b,-1,n);
		for(int i=0;i<n;i++){
			int tmp_a=((ll)(a[i].r+0.5))%p,tmp_b=((ll)(a[i].i+0.5))%p,tmp_c=((ll)(b[i].r+0.5))%p;
			h[i]=((1ll*tmp_a*(1<<30)+1ll*tmp_b*(1<<15)+tmp_c)%p+p)%p;
		}
	}
}
using Poly::MTT;
void mul(int *a,int *b,int *c){
	int len=1;
	while(len<=(n<<1)){
		len<<=1;
	}
	MTT(a,b,c,len,p);
}
int a[2][Maxn+5];
void mul_2(int len){
	static int b[2][Maxn+5],c[Maxn+5],d[Maxn+5];
	for(int i=0;i<=n;i++){
		b[0][i]=a[0][i];
		b[1][i]=a[1][i];
		c[i]=(a[0][i]+a[1][i])%p;
	}
	c[0]=(c[0]+1)%p;
	mul(a[0^(len&1)],c,d);
	for(int i=0;i<=n;i++){
		b[0][i]=(b[0][i]+d[i])%p;
	}
	mul(a[1^(len&1)],c,d);
	for(int i=0;i<=n;i++){
		b[1][i]=(b[1][i]+d[i])%p;
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<=n;j++){
			a[i][j]=b[i][j];
		}
	}
}
void add_1(int len){
	static int b[2][Maxn+5],c[Maxn+5];
	for(int i=0;i<=n;i++){
		b[0][i]=a[0][i];
		b[1][i]=a[1][i];
		c[i]=(a[0][i]+a[1][i])%p;
	}
	c[0]=(c[0]+1)%p;
	for(int i=n;i>0;i--){
		c[i]=c[i-1];
	}
	c[0]=0;
	for(int i=0;i<=n;i++){
		b[(len+1)&1][i]=(b[(len+1)&1][i]+c[i])%p;
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<=n;j++){
			a[i][j]=b[i][j];
		}
	}
}
int ans;
void solve(int m,bool flag=0){
	if(m==1){
		a[1][1]=1;
		if(flag){
			ans=1;
		}
		return;
	}
	solve(m>>1,1);
	mul_2(m>>1);
	if(m&1){
		add_1(m-1);
	}
	if(flag){
		for(int i=1;i<=n;i+=2){
			ans=(ans+a[1][i])%p;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	solve(m);
	printf("%d\n",ans);
	return 0;
}