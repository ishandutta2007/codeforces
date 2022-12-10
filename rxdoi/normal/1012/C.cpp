#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<string>
#include<bitset>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
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
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';
	return !f?x:-x;
}

const int N=5000+19;

int dp[N][N/2][3];
int A[N];
int n,m;

void upd(int &x,int y){
	if (y<x) x=y;
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	m=(n+1)/2;
	A[0]=A[n+1]=-1;
	memset(dp,60,sizeof(dp));
	dp[0][0][2]=0;
	For(i,0,n){
		For(j,0,m+1){
			For(k,0,3) if (dp[i][j][k]>=0){
				upd(dp[i+1][j][min(k+1,2)],dp[i][j][k]+(k==0?max(A[i+1]-A[i]+1,0):0));
				if (k){
					int w;
					if (k==1) w=max(min(A[i],A[i-1]-1)-A[i+1]+1,0);
					if (k==2) w=max(A[i]-A[i+1]+1,0);
					upd(dp[i+1][j+1][0],dp[i][j][k]+w);
				}
			}
		}
	}
	For(i,1,m+1){
		int tmp=(1<<30)-1;
		For(j,0,3) tmp=min(tmp,dp[n][i][j]);
		printf("%d ",tmp);
	}
	puts("");
}