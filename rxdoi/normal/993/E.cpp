#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000*4+19;
const db pi=acos(-1.0);

struct comp{
	db r,i;
} w[2][N],A[N],B[N];
int S[N],rev[N];
int n,x,c;
ll ans[N];
map<int,int> M;

comp operator + (comp A,comp B){
	return (comp){A.r+B.r,A.i+B.i};
}
comp operator - (comp A,comp B){
	return (comp){A.r-B.r,A.i-B.i};
}
comp operator * (comp A,comp B){
	return (comp){A.r*B.r-A.i*B.i,A.r*B.i+A.i*B.r};
}
void Prepare(int n){
	For(i,0,n){
		w[0][i]=w[1][i]=(comp){cos(2*pi*i/n),sin(2*pi*i/n)};
		w[1][i].i*=-1;
	}
	rev[0]=0;
	int m=0;
	while ((1<<m)!=n) m++;
	For(i,1,n) rev[i]=(rev[i>>1]>>1)|(i&1)<<m-1;
}
void FFT(comp *A,int n,int f){
	For(i,0,n) if (i<rev[i]) swap(A[i],A[rev[i]]);
	for (int i=1;i<n;i<<=1)
		for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
			for (int k=j,l=0;k<j+i;k++,l+=t){
				comp x=A[k],y=w[f][l]*A[k+i];
				A[k]=x+y;
				A[k+i]=x-y;
			}
	if (f){
		For(i,0,n) A[i].r/=n;
	}
}

int main(){
	n=IN(),x=IN();
	For(i,1,n+1) S[i]=S[i-1]+(IN()<x?1:0);
	For(i,1,n+1) A[S[i]].r++;
	For(i,0,n) B[n-S[i]].r++;
	for (c=1;c<=n;c<<=1);c<<=1;
	Prepare(c);
	FFT(A,c,0);
	FFT(B,c,0);
	For(i,0,c) A[i]=A[i]*B[i];
	FFT(A,c,1);
	M[0]++;
	For(i,1,n+1){
		ans[0]+=M[S[i]];
		M[S[i]]++;
	}
	For(i,1,n+1) ans[i]=ll(A[i+n].r+0.5);
	For(i,0,n+1) printf("%lld ",ans[i]);
	puts("");
}