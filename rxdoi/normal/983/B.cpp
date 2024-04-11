#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

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

const int N=5000+19;

int F[N][N];
int A[N];
int n,l,r;

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) F[i][i]=A[i];
	for (int i=n;i;i--) For(j,i+1,n+1){
		F[i][j]=F[i][j-1]^F[i+1][j];
	}
	For(i,1,n+1) For(j,i,n+1) F[i][j]=max(F[i][j],F[i][j-1]);
	for (int i=n;i;i--) For(j,i,n+1) F[i][j]=max(F[i][j],F[i+1][j]);
	for (int q=IN();q--;){
		l=IN(),r=IN();
		printf("%d\n",F[l][r]);
	}
}