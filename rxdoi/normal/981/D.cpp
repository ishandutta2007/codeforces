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

const int N=50+19;

ll A[N],x;
int n,k;

bool check(ll w){
	static int dp[N][N];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	For(i,1,k+1){
		For(j,1,n+1){
			For(x,1,j+1) if (((A[j]-A[x-1])&w)==w){
				dp[i][j]|=dp[i-1][x-1];
			}
		}
	}
	return dp[k][n];
}

int main(){
	n=IN(),k=IN();
	For(i,1,n+1){
		cin>>A[i];
		A[i]+=A[i-1];
	}
	for (int i=60;~i;i--){
		if (check(x|1ll<<i)) x|=1ll<<i;
	}
	cout<<x<<endl;
}