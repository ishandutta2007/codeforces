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

int A[N][N];
int n,x;

int main(){
	n=IN();
	memset(A,60,sizeof(A));
	For(i,1,n){
		int x=IN()+1,y=IN()+1;
		int z=IN();
		A[x][y]=A[y][x]=min(A[x][y],z);
	}
	For(i,1,n+1) A[i][i]=0;
	For(k,1,n+1) For(i,1,n+1) For(j,1,n+1) A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
	x=1;
	For(i,2,n+1) if (A[1][i]>A[1][x]) x=i;
	printf("%d\n",A[1][x]);
}