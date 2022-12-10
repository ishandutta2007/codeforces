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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100+19;
const ll oo=1ll<<60;

ll f[N][N][N],res;
int c[N],A[N][N];
int n,m,k;

int main(){
	n=IN(),m=IN(),k=IN();
	For(i,1,n+1) c[i]=IN();
	For(i,1,n+1) For(j,1,m+1) A[i][j]=IN();
	
	For(i,0,N) For(j,0,N) For(k,0,N) f[i][j][k]=oo;
	For(i,1,m+1){
		if (!c[1]||i==c[1]){
			f[1][1][i]=(!c[1])*A[1][i];
		}
	}
	For(i,2,n+1){
		For(j,1,k+1){
			For(x,1,m+1) if (!c[i]||x==c[i]){
				For(y,1,m+1){
					f[i][j][x]=min(f[i][j][x],f[i-1][j-(x!=y)][y]+(!c[i])*A[i][x]);
				}
			}
		}
	}
	
	res=oo;
	For(i,1,m+1) res=min(res,f[n][k][i]);
	if (res==oo){
		puts("-1");
	} else{
		printf("%I64d\n",res);
	}
}