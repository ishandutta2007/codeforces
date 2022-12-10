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

const int N=300000+19;
const int oo=(1<<30)-1;
const int S=42;

int dp[N][S];
int A[N];
int n,res=oo;

void upd(int i,int j,int v){
	if (j>=S) return;
	if (v<dp[i][j]) dp[i][j]=v;
}

int main(){
	For(i,0,N) For(j,0,S) dp[i][j]=oo;
	n=IN();
	For(i,0,n) A[i]=IN();
	dp[0][0]=0;
	For(i,0,n) For(j,0,S) if (dp[i][j]!=oo){
		upd(i+1,j+A[i]/1000,dp[i][j]+A[i]);
		int tmp=min(j*100,A[i]);
		upd(i+1,j-tmp/100+(tmp==0?A[i]/1000:0),dp[i][j]+A[i]-tmp);
	}
	For(j,0,S) res=min(res,dp[n][j]);
	printf("%d\n",res);
}