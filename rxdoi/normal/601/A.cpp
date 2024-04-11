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

const int N=400+19;
const int oo=(1<<30)-1;

int A[N][N],B[N][N],vis[N][N];
int n,x,y;

int main(){
	n=IN();
	For(i,1,n+1) For(j,1,n+1) A[i][j]=B[i][j]=oo;
	for (int m=IN();m--;){
		x=IN(),y=IN();
		vis[x][y]=vis[y][x]=1;
	}
	For(i,1,n+1) For(j,1,n+1)
		if (vis[i][j]){
			A[i][j]=1;
		} else{
			B[i][j]=1;
		}
	For(k,1,n+1) For(i,1,n+1) For(j,1,n+1){
		A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
		B[i][j]=min(B[i][j],B[i][k]+B[k][j]);
	}
	if (A[1][n]==oo||B[1][n]==oo){
		puts("-1");
	} else{
		printf("%d\n",max(A[1][n],B[1][n]));
	}
}