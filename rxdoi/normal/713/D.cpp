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
#define mid (x+y>>1)

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

const int N=1000+3;

int A[N][N],s[N][N],val[N][N];
int n,m,U,L,D,R,x,y,res;

int f[10][10][N][N],Lg[N];

void Init(){
	For(i,1,n+1) For(j,1,m+1) f[0][0][i][j]=val[i][j];
	For(x,1,10){
		for (int i=1;i+(1<<x)-1<=n;i++)
			for (int j=1;j<=m;j++){
				f[x][0][i][j]=max(f[x-1][0][i][j],f[x-1][0][i+(1<<x-1)][j]);
			}
	}
	For(x,0,10)
		For(y,1,10){
			for (int i=1;i+(1<<x)-1<=n;i++)
				for (int j=1;j+(1<<y)-1<=m;j++){
					f[x][y][i][j]=max(f[x][y-1][i][j],f[x][y-1][i][j+(1<<y-1)]);
				}
		}
}
int Qry(int U,int L,int D,int R){
	int x=Lg[D-U+1],y=Lg[R-L+1],res=0;
	res=max(res,f[x][y][U][L]);
	res=max(res,f[x][y][D-(1<<x)+1][L]);
	res=max(res,f[x][y][U][R-(1<<y)+1]);
	res=max(res,f[x][y][D-(1<<x)+1][R-(1<<y)+1]);
	return res;
}

int main(){
	For(i,0,10) if ((1<<i)<N) Lg[1<<i]=i;
	For(i,1,N) Lg[i]=max(Lg[i],Lg[i-1]);
	n=IN(),m=IN();
	For(i,1,n+1){
		For(j,1,m+1){
			A[i][j]=IN();
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+A[i][j];
		}
	}
	for (int i=n;i;i--)
		for (int j=m;j;j--)
			if (A[i][j]){
				val[i][j]=min(min(val[i][j+1],val[i+1][j]),val[i+1][j+1])+1;
			}
	Init();
	for (int Qc=IN();Qc--;){
		U=IN(),L=IN(),D=IN(),R=IN();
		x=1,y=min(D-U+1,R-L+1);res=0;
		while (x<=y){
			int tmp=Qry(U,L,D-mid+1,R-mid+1);
			if (tmp>=mid) res=mid,x=mid+1;else y=mid-1;
		}
		printf("%d\n",res);
	}
}