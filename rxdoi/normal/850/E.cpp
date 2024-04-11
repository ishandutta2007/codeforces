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

const int N=1<<20;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int f[N],g[N];
int n,res;
char s[N+19];

void FWT(int *A,int n,int f){
	for (int i=1;i<n;i<<=1)
		for (int j=0;j<n;j+=i<<1){
			For(k,j,j+i){
				int u=A[k],v=A[k+i];
				A[k]=(u+v)%p;
				A[k+i]=(u-v+p)%p;
			}
		}
	if (f){
		int tmp=Pow(n,p-2);
		For(i,0,n) A[i]=1ll*A[i]*tmp%p;
	}
}

int main(){
	n=IN();
	scanf("%s",s);
	For(i,0,1<<n) f[i]=s[i]-'0';
	FWT(f,1<<n,0);
	For(i,0,1<<n) f[i]=1ll*f[i]*f[i]%p;
	FWT(f,1<<n,1);
	For(t,0,1<<n){
		g[t]=1<<n-__builtin_popcount(t);
		res=(res+1ll*f[t]*g[t])%p;
	}
	res=3ll*res%p;
	printf("%d\n",res);
}