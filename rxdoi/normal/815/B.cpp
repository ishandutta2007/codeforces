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

const int N=200000+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int fac[N],inv[N];
int n,A[N],B[N],T[N],res;

int C(int n,int m){
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	if (n%4==1){
		For(i,1,n+1){
			if (i%2==0) B[i]=0;else B[i]=C(n/2,i/2);
		}
	}
	if (n%4==2){
		For(i,1,n+1){
			B[i]=C((n-1)/2,(i-1)/2);
		}
	}
	if (n%4==3){
		For(i,1,n){
			T[i]=C((n-2)/2,(i-1)/2);
		}
		For(i,1,n+1){
			B[i]=(i&1)?(T[i]-T[i-1]+p)%p:(T[i]+T[i-1])%p;
		}
	}
	if (n%4==0){
		For(i,1,n+1){
			B[i]=C((n-1)/2,(i-1)/2);
			if (i%2==0) B[i]=p-B[i];
		}
	}
	For(i,1,n+1) res=(res+1ll*B[i]*A[i])%p;
	printf("%d\n",res);
}