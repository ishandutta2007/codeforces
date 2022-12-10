#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(i,x,y) for (int i=x;i<=y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=5000+19;

short f[N][N],g1[N][N],w1[N][7],g2[N][N],w2[N][7],res;
int A[N],id[100000+19];
int n,num;

void Upd(short &x,short y){
	if (y>x) x=y;
}

int main(){
	n=IN();
	For(i,1,n+1){
		A[i]=IN();
		if (!id[A[i]]) id[A[i]]=++num;
	}
	memset(g1,200,sizeof(g1));
	memset(w1,200,sizeof(w1));
	memset(g2,200,sizeof(g2));
	memset(w2,200,sizeof(w2));
	For(j,1,n+1){
		f[0][j]=1;
		For(i,0,j){
			Upd(f[i][j],f[0][i]+1);
			Rep(d,-1,1){
				if (id[A[j]+d]){
					Upd(f[i][j],g1[i][id[A[j]+d]]+1);
					Upd(f[i][j],g2[i][id[A[j]+d]]+1);
				}
			}
			Upd(f[i][j],w1[i][A[j]%7]+1);
			Upd(f[i][j],w2[i][A[j]%7]+1);
			Upd(g1[i][id[A[j]]],f[i][j]);
			Upd(w1[i][A[j]%7],f[i][j]);
			Upd(g2[j][id[A[i]]],f[i][j]);
			Upd(w2[j][A[i]%7],f[i][j]);
			/*
			For(x,1,j){
				if (fabs(A[j]-A[x])<=1||(A[j]-A[x])%7==0) f[i][j]=max(f[i][j],f[i][x]+1);
			}
			For(x,1,i){
				if (fabs(A[j]-A[x])<=1||(A[j]-A[x])%7==0) f[i][j]=max(f[i][j],f[x][i]+1);
			}
			*/
			Upd(res,f[i][j]);
		}
	}
	cout<<res<<endl;
}