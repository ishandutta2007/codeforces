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

const int N=500+19;

ll A[N][N],sum;
int n,x,y;

bool check(){
	For(i,1,n+1){
		ll tmp=0;
		For(j,1,n+1) tmp+=A[i][j];
		if (tmp!=sum) return 0;
	}
	For(i,1,n+1){
		ll tmp=0;
		For(j,1,n+1) tmp+=A[j][i];
		if (tmp!=sum) return 0;
	}
	ll tmp=0;
	For(i,1,n+1) tmp+=A[i][i];
	if (tmp!=sum) return 0;
	tmp=0;
	For(i,1,n+1) tmp+=A[i][n-i+1];
	if (tmp!=sum) return 0;
	return 1;
}

int main(){
	n=IN();
	For(i,1,n+1) For(j,1,n+1){
		A[i][j]=IN();
		if (A[i][j]==0) x=i,y=j;
	}
	if (n==1){
		puts("1");
		return 0;
	}
	if (x==1){
		For(i,1,n+1) sum+=A[2][i];
	} else{
		For(i,1,n+1) sum+=A[1][i];
	}
	For(i,1,n+1) if (y!=i) A[x][y]-=A[x][i];
	A[x][y]+=sum;
	if (check()&&A[x][y]>0){
		printf("%I64d\n",A[x][y]);
	} else{
		puts("-1");
	}
}