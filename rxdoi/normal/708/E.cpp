#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

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

const int N=1500+19;
const int M=100000+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int A[N][N],B[N][N];
int fac[M],inv[M],pw[M],iv[M];
int n,m,a,b,pro,k,t1,t2,t3,t4;

void Init(){
	fac[0]=1;
	For(i,1,M) fac[i]=1ll*fac[i-1]*i%p;
	inv[M-1]=Pow(fac[M-1],p-2);
	for (int i=M-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	pw[0]=1;
	For(i,1,M) pw[i]=1ll*pw[i-1]*pro%p;
	iv[0]=1;
	For(i,1,M) iv[i]=1ll*iv[i-1]*(1-pro+p)%p;
}
int calc(int x){
	if (x>k) return 0;
	return 1ll*pw[x]*iv[k-x]%p*fac[k]%p*inv[x]%p*inv[k-x]%p;
}

int main(){
	n=IN(),m=IN(),a=IN(),b=IN(),k=IN();
	pro=1ll*a*Pow(b,p-2)%p;
	Init();
	For(i,1,m+1) A[0][i]=1;
	B[0][m]=1;
	For(i,1,n+1){
		t1=0;t2=0;t3=0;t4=0;
		for (int j=m;j>=1;j--){
			t1=(t1+1ll*calc(m-j)*A[i-1][j])%p;
			t2=(t2+calc(m-j))%p;
			A[i][j]=1ll*calc(j-1)*(t1-1ll*t2*B[i-1][j-1]%p+p)%p;
		}
		for (int j=1;j<=m;j++){
			t3=(t3+calc(j-1))%p;
			t4=(t4+1ll*calc(j-1)*B[i-1][j-1])%p;
			B[i][j]=1ll*calc(m-j)*(1ll*t3*A[i-1][j]%p-t4+p)%p;
		}
		For(j,1,m+1){
			A[i][j]=(A[i][j-1]+A[i][j])%p;
			B[i][j]=(B[i][j-1]+B[i][j])%p;
		}
	}
	printf("%d\n",A[n][m]);
}