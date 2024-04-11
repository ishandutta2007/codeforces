#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=1100000;
int n,m;
char a[N],tmp[N];
int b[N];
inline void mul(int *A,int *B,int *C){
	rep(i,1,n)C[i]=A[B[i]];
}
int left[N];
int work[N];
int comb[N];
int final[N];
int U[N],V[N];
int W[N];
void Pow(int *A,int ti){
	rep(i,1,n)U[i]=i;
	rep(i,1,n)V[i]=A[i];
	while(ti){
		if(ti&1){
			mul(U,V,W);
			rep(i,1,n)U[i]=W[i];
		}
		ti>>=1;
		mul(V,V,W);
		rep(i,1,n)V[i]=W[i];
	}
	rep(i,1,n)A[i]=U[i];
}
int main(){
	scanf("%s",a+1);n=strlen(a+1);
	scanf("%d",&m);
	while(m--){
		int k,d;scanf("%d%d",&k,&d);
		rep(i,1,n){
			b[i]=i;
			left[i]=i%n+1;
		}
		int top=0;
		rep(i,1,d){
			int v=i;
			while(v<=k){
				work[++top]=v;
				v+=d;
			}
		}
		rep(i,top+1,n)work[i]=i;
		mul(work,left,comb);
		Pow(comb,n-k);
		mul(comb,work,final);
		rep(i,1,n)tmp[i]=a[i];
		rep(i,1,n)a[(i+(n-k)-1)%n+1]=tmp[final[i]];
		rep(i,1,n)printf("%c",a[i]);printf("\n");
	}
	return 0;
}