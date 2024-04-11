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
const int P=1000000007;
const int N=105;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int n;
int dv[N],du[N];
int v[N];
int a[N][N];
int det(int n){
	int ans=1;
	rep(i,1,n){
		int d=0;
		rep(j,i,n)if(a[j][i]!=0)d=j;
		if(!d)return 0;
		if(d^i){
			ans=(P-ans)%P;
			rep(k,1,n)swap(a[d][k],a[i][k]);
		}
		int V=Pow(a[i][i],P-2);
		rep(j,i+1,n)if(a[j][i]!=0){
			int w=a[j][i]*1ll*V%P;
			rep(k,1,n)a[j][k]=(a[j][k]+P-(w*1ll*a[i][k]%P))%P;
		}
	}
	rep(i,1,n)ans=ans*1ll*a[i][i]%P;
	return ans;
}
int calc(int x){
	memset(a,0,sizeof a);
	rep(i,1,n)rep(j,i+1,n){
		a[i][j]=(a[i][j]+P-1)%P;
		a[j][i]=(a[j][i]+P-1)%P;
		a[i][i]++;
		a[j][j]++;
	}
	rep(i,1,n-1){
		a[du[i]][dv[i]]=(a[du[i]][dv[i]]+1+P-x)%P;
		a[dv[i]][du[i]]=(a[dv[i]][du[i]]+1+P-x)%P;	
		a[du[i]][du[i]]=(a[du[i]][du[i]]+P-1+x)%P;
		a[dv[i]][dv[i]]=(a[dv[i]][dv[i]]+P-1+x)%P;
	}
	return det(n-1);
}
int f[N];
int g[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&du[i],&dv[i]);
	}
	rep(i,0,n){
		v[i]=calc(i);
	}

	rep(i,0,n){
		int xi=1;
		rep(j,0,n)if(i!=j)xi=xi*1ll*(i-j+P)%P;
		memset(g,0,sizeof g);
		g[0]=Pow(xi,P-2)*1ll*v[i]%P;
		rep(j,0,n)if(i!=j){
			int d1=(P-j)%P;
			per(k,n,0){
				g[k]=g[k]*1ll*d1%P;
				if(k)
				g[k]=(g[k]+g[k-1])%P;
			}
		}
		rep(j,0,n)f[j]=(f[j]+g[j])%P;
	}
	rep(i,0,n-1)printf("%d ",f[i]);
	puts("");
	return 0;
}