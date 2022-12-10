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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=100000+19;
const int p=1e9+7;

int fac[N],inv[N],pw10[N],f[N];
int n,k,res,tmp;
char s[N];

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}
int C(int n,int m){
	if (n<m) return 0;
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	pw10[0]=1;
	For(i,1,N) pw10[i]=10ll*pw10[i-1]%p;
	
	n=IN(),k=IN();
	scanf("%s",s+1);
	if (k==0){
		For(i,1,n+1) res=(10ll*res+s[i]-'0')%p;
		printf("%d\n",res);
		return 0;
	}
	For(i,1,n+1){
		f[i]=(f[i-1]+1ll*pw10[i-1]*C(n-i-1,k-1))%p;
	}
	For(i,1,n+1){
		res=(res+1ll*(s[i]-'0')*f[n-i])%p;
	}
	for (int i=n;i;i--){
		tmp=(tmp+1ll*(s[i]-'0')*pw10[n-i])%p;
		res=(res+1ll*tmp*C(i-2,k-1))%p;
	}
	printf("%d\n",res);
}