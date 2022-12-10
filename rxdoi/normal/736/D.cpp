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

const int N=2000+19;
const int M=500000+19;

bitset<N> A[N],I[N];
int cof[N][N];
int x[M],y[M];
int n,m;

void getinv(){
	For(i,1,n+1) I[i].set(i);
	For(i,1,n+1){
		if (!A[i][i])
			For(j,i+1,n+1) if (A[j][i]){
				swap(A[i],A[j]);
				swap(I[i],I[j]);
				break;
			}
		For(j,1,n+1) if (j!=i&&A[j][i]){
			A[j]^=A[i];
			I[j]^=I[i];
		}
	}
}

int main(){
	n=IN(),m=IN();
	For(i,1,m+1){
		x[i]=IN(),y[i]=IN();
		A[x[i]].set(y[i]);
	}
	getinv();
	For(i,1,n+1){
		For(j,1,n+1) if (I[i][j]) cof[j][i]=1;
	}
	For(i,1,m+1){
		puts(cof[x[i]][y[i]]?"NO":"YES");
	}
}