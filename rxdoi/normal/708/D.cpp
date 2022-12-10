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

const int N=500+19;
db A[N][N],b[N],c[N];

namespace Simplex{
	const db eps=1e-9;
	db res[N],z;
	int X[N],Y[N];
	int n,m,t;
	
	void pivot(int x,int y){
		swap(X[y],Y[x]);
		b[x]/=A[x][y];
		For(i,1,m+1) if (i!=y) A[x][i]/=A[x][y];
		A[x][y]=1/A[x][y];
		For(i,1,n+1)
			if (i!=x&&fabs(A[i][y])>eps){
				b[i]-=A[i][y]*b[x];
				For(j,1,m+1) if (j!=y) A[i][j]-=A[i][y]*A[x][j];
				A[i][y]=-A[i][y]*A[x][y];
			}
		z+=c[y]*b[x];
		For(i,1,m+1) if (i!=y) c[i]-=c[y]*A[x][i];
		c[y]=-c[y]*A[x][y];
	}
	void simplex(){
		For(i,1,m+1) X[i]=i;
		For(i,1,n+1) Y[i]=i+m;
		for (;;){
			db mn=-eps;
			int x=0,y=0;
			For(i,1,n+1) if (b[i]<mn) mn=b[i],x=i;
			if (!x) break;
			For(i,1,m+1) if (A[x][i]<-eps) {y=i;break;}
			if (!y){
				puts("Infeasible");
				exit(0);
			}
			pivot(x,y);
		}
		for (;;){
			int x=0,y=0;
			For(i,1,m+1) if (c[i]>eps) {y=i;break;}
			if (!y) break;
			db mn=1e60;
			For(i,1,n+1) if (A[i][y]>eps&&b[i]/A[i][y]<mn) mn=b[i]/A[i][y],x=i;
			if (!x){
				puts("Unbounded");
				exit(0);
			}
			pivot(x,y);
		}
	}
	db Main(){
		simplex();
		return z;
	}
}

struct Edge{
	int x,y,c,f,A,B,C;
} E[N];
Vi I[N],O[N];
int n,m,idx,idy;

int main(){
	n=IN(),m=IN();
	For(i,1,m+1){
		E[i]=(Edge){IN(),IN(),IN(),IN(),0,0,0};
		E[i].A=++idy;
		E[i].B=++idy;
		E[i].C=++idy;
		O[E[i].x].pb(i);
		I[E[i].y].pb(i);
		idx++;
		A[idx][E[i].A]=1;
		b[idx]=E[i].f;
		idx++;
		A[idx][E[i].A]=-1;
		A[idx][E[i].B]=1;
		A[idx][E[i].C]=-1;
		b[idx]=E[i].c-E[i].f;
		c[E[i].A]=-1;
		c[E[i].B]=-1;
		c[E[i].C]=-1;
	}
	For(x,2,n){
		idx++;
		For(i,0,I[x].size()){
			int t=I[x][i];
			A[idx][E[t].A]--;
			A[idx][E[t].B]++;
			b[idx]-=E[t].f;
		}
		For(i,0,O[x].size()){
			int t=O[x][i];
			A[idx][E[t].A]++;
			A[idx][E[t].B]--;
			b[idx]+=E[t].f;
		}
		idx++;
		For(j,1,idy+1) A[idx][j]=-A[idx-1][j];
		b[idx]=-b[idx-1];
	}
	Simplex::n=idx;
	Simplex::m=idy;
	printf("%d\n",-int(floor(Simplex::Main()+0.5)));
}