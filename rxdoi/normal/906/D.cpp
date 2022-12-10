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
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;
const int oo=(1<<30)-1;

int phi[50],A[N],c2[N];
int n,p,l,r;

int Pow(int a,int b,int p){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}
int getphi(int n){
	int res=n;
	for (int i=2;1ll*i*i<=n;i++)
		if (n%i==0){
			res=res/i*(i-1);
			while (n%i==0) n/=i;
		}
	if (n>1){
		res=res/n*(n-1);
	}
	return res;
}
int cal2(int x){
	if (A[x]==1||x==r+1) return 1;
	int t=c2[x+1];
	if (t>30||pow(A[x],t)>=oo) return oo;
	return Pow(A[x],t,oo);
}
int cal(int x,int d){
	if (x==r+1) return 1;
	if (phi[d]==1) return 0;
	if (cal2(x+1)>phi[d+1]){
		return Pow(A[x],cal(x+1,d+1)+phi[d+1],phi[d]);
	} else{
		return Pow(A[x],cal2(x+1),phi[d]);
	}
}

int main(){
	n=IN(),p=IN();
	For(i,0,50){
		phi[i]=p;
		p=getphi(p);
	}
	For(i,1,n+1) A[i]=IN();
	for (int q=IN();q--;){
		l=IN(),r=IN();
		for (int i=min(r+1,l+30);i>=l;i--) c2[i]=cal2(i);
		printf("%d\n",cal(l,0));
	}
}