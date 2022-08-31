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
const int N=1005;
const int P=1000000007;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int cnt[N];
int n,k;
char a[N];
int num[N];
int f[N][N][2];
int main(){
	rep(i,1,1000)cnt[i]=cnt[i>>1]+(i&1);	
	scanf("%s",a+1);
	n=strlen(a+1);
	scanf("%d",&k);
	if(k==0){
		printf("1\n");
		return 0;
	}
	--k;
	rep(i,2,n){
		num[i]=num[cnt[i]]+1;
	}
	f[1][0][1]=1;
	rep(i,1,n)rep(j,0,n)rep(d,0,1){
		rep(c,0,1){
			if((c>(a[i]-'0'))&&d)continue;
			f[i+1][j+c][d&(c==(a[i]-'0'))]=(f[i+1][j+c][d&(c==(a[i]-'0'))]+f[i][j][d])%P;
		}
	}
	int ans=0;
	rep(i,1,n)rep(d,0,1)if(num[i]==k)ans=(ans+f[n+1][i][d])%P;
	if(!k){
		ans=(ans+P-1)%P;
	}
	printf("%d\n",ans);
	return 0;
}