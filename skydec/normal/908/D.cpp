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
int f[N][N];
int n,pa,pb;
int ans=0;
int main(){
	scanf("%d%d%d",&n,&pa,&pb);
	int ww=(pa+pb)%P;
	ww=Pow(ww,P-2);
	pa=pa*1ll*ww%P;
	pb=pb*1ll*ww%P;
	f[0][0]=1;
	int cd=0;
	rep(i,0,n)rep(j,0,n)if(f[i][j]){
		if(i+j>=n){
			int w=f[i][j];
			w=w*1ll*(i+j+Pow(P+1-pa,P-2)-1)%P;
			ans=(ans+w)%P;
			cd=(cd+w)%P;
		}
		else if(i+j){
			f[i][j+i]=(f[i][j+i]+f[i][j]*1ll*pb)%P;
			f[i+1][j]=(f[i+1][j]+f[i][j]*1ll*pa)%P;
		}
		else{
			f[i+1][j]=f[i][j];
		}
	}
	printf("%d\n",ans);
	return 0;
}