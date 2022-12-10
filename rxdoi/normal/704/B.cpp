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

const int N=5000+19;
const ll oo=1ll<<60;

ll f[2][N][2][2];
ll X[N],A[N],B[N],C[N],D[N];
ll tmp;
int n,s,t,c;

void U(ll &x,ll y){
	if (x>y) x=y;
}

int main(){
	n=IN(),s=IN(),t=IN();
	For(i,1,n+1) X[i]=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=IN();
	For(i,1,n+1) C[i]=IN();
	For(i,1,n+1) D[i]=IN();
	For(j,0,N) For(x,0,2) For(y,0,2) f[c][j][x][y]=oo;
	f[c][0][0][0]=0;
	For(i,1,n+1){
		For(j,0,N) For(x,0,2) For(y,0,2) f[c^1][j][x][y]=oo;
		For(j,0,n+1) For(x,0,2) For(y,0,2)
			if ((tmp=f[c][j][x][y])!=oo){
				if (i==s){
					if (j>=1) U(f[c^1][j-1][1][y],tmp+X[i]+C[i]);
					if (y>=1) U(f[c^1][j][0][y-1],tmp+X[i]+C[i]);
					U(f[c^1][j][1][y],tmp-X[i]+D[i]);
				} else
				if (i==t){
					if (j>=1) U(f[c^1][j-1][x][1],tmp+X[i]+A[i]);
					if (x>=1) U(f[c^1][j][x-1][0],tmp+X[i]+A[i]);
					U(f[c^1][j][x][1],tmp-X[i]+B[i]);
				} else{
					//1
					if (j>=2) U(f[c^1][j-1][x][y],tmp+2*X[i]+A[i]+C[i]);
					if (x>=1&&j>=1) U(f[c^1][j-1][x][y],tmp+2*X[i]+A[i]+C[i]);
					if (y>=1&&j>=1) U(f[c^1][j-1][x][y],tmp+2*X[i]+A[i]+C[i]);
					if (x>=1&&y>=1) U(f[c^1][j][0][0],tmp+2*X[i]+A[i]+C[i]);
					//2
					if (j>=1) U(f[c^1][j][x][y],tmp+A[i]+D[i]);
					if (x>=1) U(f[c^1][j][x][y],tmp+A[i]+D[i]);
					//3
					if (j>=1) U(f[c^1][j][x][y],tmp+B[i]+C[i]);
					if (y>=1) U(f[c^1][j][x][y],tmp+B[i]+C[i]);
					//4
					U(f[c^1][j+1][x][y],tmp-2*X[i]+B[i]+D[i]);
				}
			}
		c^=1;
	}
	printf("%I64d\n",f[c][0][0][0]);
}