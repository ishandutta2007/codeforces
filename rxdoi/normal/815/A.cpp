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

const int N=100+19;
const int oo=(1<<30)-1;

int A[N][N],B[N][N],c[N];
int n,m,rev;
Vi V;

int main(){
	n=IN(),m=IN();
	For(i,1,n+1) For(j,1,m+1) A[i][j]=IN();
	if (n>m){
		swap(n,m);
		For(i,1,n+1) For(j,1,m+1) B[i][j]=A[j][i];
		For(i,1,n+1) For(j,1,m+1) A[i][j]=B[i][j];
		rev=1;
	}
	For(i,1,n+1){
		int mn=oo;
		For(j,1,m+1) mn=min(mn,A[i][j]);
		For(j,1,m+1) A[i][j]-=mn;
		For(j,0,mn) V.pb(i);
	}
	For(j,1,m+1){
		int chk=1;
		For(i,1,n+1) if (A[i][j]!=A[1][j]) chk=0;
		if (!chk){
			puts("-1");
			return 0;
		}
		For(i,0,A[1][j]) V.pb(-j);
	}
	printf("%d\n",V.size());
	For(i,0,V.size()){
		if ((V[i]>0)==(rev==0)) printf("row ");else printf("col ");
		printf("%d\n",abs(V[i]));
	}
}