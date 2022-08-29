#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=5005;
const int P=1000000007;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int n,k;
int f[N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,0,k)f[i]=Pow(i,k);
	int ans=0;
	int tmp=1;
	rep(i,0,min(n,k)){
		int w=tmp*1ll*Pow(2,n-i)%P;
		w=w*1ll*f[0]%P;
		ans=(ans+w)%P;
		tmp=tmp*1ll*(n-i)%P;
		if(tmp==0)break;
		tmp=tmp*1ll*Pow(i+1,P-2)%P;
		rep(j,0,k-i-1)f[j]=(f[j+1]+P-f[j])%P;
	}
	printf("%d\n",ans);
	return 0;
}