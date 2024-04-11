#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=300000*4+19;

ll w[2][N],A2[N],B2[N],C2[N];
int rev[N],A[N],B[N],C[N],P[N];
int n,len,g;
ll a,b,c,sum,p;
set<ll> S;

ll mul(ll a,ll b){
	return a*b-(ll)((long double)a*b/p)*p;
}
ll Pow(ll a,ll b){
	ll res=1;
	for (;b;b>>=1,a=mul(a,a)) if (b&1) res=mul(res,a);
	return res;
}
void Init(){
	for (len=1;len<2*n;len<<=1);len<<=1;
	ll lcm=1ll*n*len/__gcd(n,len);
	p=lcm+1;
	while (p<100000) p+=lcm;
	for (;;p+=lcm){
		int chk=1;
		for (int j=2;1ll*j*j<=p&&chk;j++) if (p%j==0) chk=0;
		if (chk) break;
	}
	for (g=2;;g++){
		int chk=1;
		for (int j=2;1ll*j*j<=p-1&&chk;j++)
			if ((p-1)%j==0){
				if (Pow(g,j)==1) chk=0;
				if (Pow(g,(p-1)/j)==1) chk=0;
			}
		if (chk) break;
	}
}

void Prepare(int n){
	ll w0=Pow(g,(p-1)/n);
	w[0][0]=w[1][0]=1;
	For(i,1,n) w[0][i]=mul(w[0][i-1],w0);
	For(i,1,n) w[1][i]=w[0][n-i];
	int m;
	for (m=0;(1<<m)!=n;m++);
	rev[0]=0;
	For(i,1,n) rev[i]=(rev[i>>1]>>1)|(i&1)<<m-1;
}
void FFT(ll *A,int n,int f){
	For(i,0,n) if (i<rev[i]) swap(A[i],A[rev[i]]);
	for (int i=1;i<n;i<<=1)
		for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
			for (int k=j,l=0;k<j+i;k++,l+=t){
				ll x=A[k],y=mul(w[f][l],A[k+i]);
				A[k]=(x+y>=p?x+y-p:x+y);
				A[k+i]=(x-y+p>=p?x-y:x-y+p);
			}
	if (f){
		ll tmp=Pow(n,p-2);
		For(i,0,n) A[i]=mul(A[i],tmp);
	}
}

ll W[2][N],F[N],G[N];
void preDFT(int f){
	ll w0=Pow(g,(p-1)/n);
	W[0][0]=W[1][0]=1;
	For(i,1,n) W[0][i]=mul(W[0][i-1],w0);
	For(i,1,n) W[1][i]=W[0][n-i];
	For(i,0,2*n) G[2*n-1-i]=W[f][1ll*i*(i-1)/2%n];
	For(i,2*n,len) G[i]=0;
	for (len=1;len<2*n;len<<=1);len<<=1;
	Prepare(len);
	FFT(G,len,0);
}
void DFT(ll *A,int n,int f){
	For(i,0,n) F[i]=mul(A[i],W[f][(n-1ll*i*(i-1)/2%n)%n]);
	For(i,n,len) F[i]=0;
	FFT(F,len,0);
	For(i,0,len) F[i]=mul(F[i],G[i]);
	FFT(F,len,1);
	For(i,0,n){
		A[i]=mul(F[2*n-1-i],W[f][(n-1ll*i*(i-1)/2%n)%n]);
	}
	if (f){
		ll tmp=Pow(n,p-2);
		For(i,0,n) A[i]=mul(A[i],tmp);
	}
}

int main(){
	n=IN();
	For(i,0,n) B[i]=IN();
	For(i,0,n) C[i]=IN();
	Init();
//	dprintf("%I64d %d\n",p,g);
	For(i,0,n){
		B2[i]=B[i];
		C2[i]=mul(C[(i+1)%n]-C[i]+p,Pow(p-2,p-2));
	}
	reverse(B2+1,B2+n);
	preDFT(0);
	DFT(B2,n,0);
	DFT(C2,n,0);
	For(i,0,n) A2[i]=mul(C2[i],Pow(B2[i],p-2));
	preDFT(1);
	DFT(A2,n,1);
	For(i,0,n){
		ll v=(A2[i]<p-A2[i])?A2[i]:A2[i]-p;
		if (abs(v)>20000) return puts("0"),0;
		A[i]=v;
	}
	c=-C[0];
	For(i,0,n){
		a++;
		b+=2*(sum-B[i]);
		c+=(sum-B[i])*(sum-B[i]);
		sum+=A[i];
	}
	if (sum!=0) return puts("0"),0;
	//assert(sum==0);
	if (b*b-4*a*c>=0){
		ll s=ll(sqrt(b*b-4*a*c)+0.5);
		if (s*s!=b*b-4*a*c) return puts("0"),0;
		if ((-b+s)%(2*a)==0) S.insert((-b+s)/(2*a));
		if ((-b-s)%(2*a)==0) S.insert((-b-s)/(2*a));
	}
	printf("%d\n",S.size());
	for (ll A0:S){
		ll tmp=A0;
		For(i,0,n){
			printf("%I64d ",tmp);
			tmp+=A[i];
		}
		puts("");
	}
}