#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef long double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=65536+19;
const db pi=acos(-1.0);

struct comp{
	db r,i;
} w[2][N];
int rev[N],F[2][N],A[N],B[N],res[2][N];
int m,n,p,ans,c;

comp operator + (comp A,comp B) {return (comp){A.r+B.r,A.i+B.i};}
comp operator - (comp A,comp B) {return (comp){A.r-B.r,A.i-B.i};}
comp operator * (comp A,comp B){
	return (comp){A.r*B.r-A.i*B.i,A.r*B.i+A.i*B.r};
}

void Prepare(int n){
	For(i,0,n){
		w[0][i]=w[1][i]=(comp){cos(2*pi*i/n),sin(2*pi*i/n)};
		w[1][i].i*=-1;
		rev[i]=0;
		for (int x=i,&y=rev[i],k=1;k<n;k<<=1,x>>=1) y=(y<<1)|(x&1);
	}
}
void FFT(comp *A,int n,int f){
	comp x,y;
	For(i,0,n) if (i<rev[i]) swap(A[i],A[rev[i]]);
	for (int i=1;i<n;i<<=1)
		for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
			for (int k=j,l=0;k<j+i;k++,l+=t){
				x=A[k],y=w[f][l]*A[k+i];
				A[k]=x+y;
				A[k+i]=x-y;
			}
	if (f){
		For(i,0,n) A[i].r/=n;
	}
}
void Mul(int *A,int *B,int *C,int n,int m){
	static comp F[N],G[N];
	for (c=1;c<n+m;c<<=1);
	For(i,0,n) F[i]=(comp){A[i],0};
	For(i,n,c) F[i]=(comp){0,0};
	For(i,0,m) G[i]=(comp){B[i],0};
	For(i,m,c) G[i]=(comp){0,0};
	Prepare(c);
	FFT(F,c,0);
	FFT(G,c,0);
	For(i,0,c) F[i]=F[i]*G[i];
	FFT(F,c,1);
	For(i,0,c){
		C[i]=(C[i]+ll(F[i].r+0.5))%p;
	}
}

void Upd(int &x,int y){
	x=(x+y)%p;
}
void work(int n){
	if (n==1){
		F[0][1]=1;
		if (n!=::n){
			For(i,1,m+1) if (i&1) Upd(ans,F[0][i]);
		}
		return;
	}
	work(n/2);
	memset(res,0,sizeof(res));
	For(i,1,m+1) A[i]=(F[0][i]+F[1][i])%p;
	For(t,0,2){
		Mul(A,F[t],res[t^((n/2)&1)],m+1,m+1);
		For(i,1,m+1){
			Upd(res[t][i],F[t][i]);
			Upd(res[t^((n/2)&1)][i],F[t][i]);
		}
	}
	memcpy(F,res,sizeof(res));
	if (n&1){
		for (int i=m;i;i--){
			Upd(F[0][i],(F[0][i-1]+F[1][i-1])%p);
		}
		Upd(F[0][1],1);
	}
	if (n!=::n){
		For(i,1,m+1) if (i&1) Upd(ans,F[0][i]);
	}
}

int main(){
	m=IN(),n=IN(),p=IN();
	work(n);
	printf("%d\n",ans);
}