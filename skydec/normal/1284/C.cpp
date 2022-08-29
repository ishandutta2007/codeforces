#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
int P;
const int N=260000;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int n;
int fac[N],inv[N];
int C(int a,int b){
	return (fac[a]*1ll*inv[b]%P)*1ll*inv[a-b]%P;
}
int main(){
	scanf("%d%d",&n,&P);
	fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
	inv[n]=Pow(fac[n],P-2);per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
	int ans=0;
	rep(len,1,n){
		int w=n-len+1;
		w=w*1ll*(n-len+1)%P;
		w=w*1ll*fac[len]%P;
		w=w*1ll*fac[n-len]%P;
		ans=(ans+w)%P;
	}
	printf("%d\n",ans);
	return 0;
}