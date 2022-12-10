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

const int N=2000+19;

Vi A[800];
int id[10][10][10][10];
int dp[N][800][10];
int len[800],vis[800][10];
int a[N],b[N];
int cnt,ans,n;

void upd(int &x,int y){
	if (y<x) x=y;
}

int main(){
	For(i,0,10) For(j,i,10) For(k,j,10) For(l,k,10){
		A[cnt]=(Vi){i,j,k,l};
		len[cnt]=(i>0)+(j>0)+(k>0)+(l>0);
		vis[cnt][i]=vis[cnt][j]=vis[cnt][k]=vis[cnt][l]=1;
		id[i][j][k][l]=cnt++;
	}
	n=IN();
	For(i,0,n) a[i]=IN(),b[i]=IN();
	memset(dp,60,sizeof(dp));
	dp[0][0][1]=0;
	For(i,0,n+1){
		for (int j=cnt-1;~j;j--){
			for (int k=1;k<9;k++){
				upd(dp[i][j][k+1],dp[i][j][k]+1);
			}
			for (int k=9;k>1;k--){
				upd(dp[i][j][k-1],dp[i][j][k]+1);
			}
			For(k,1,10){
				if (a[i]==k&&len[j]<4){
					Vi T=A[j];
					T[0]=b[i];
					sort(T.begin(),T.end());
					upd(dp[i+1][id[T[0]][T[1]][T[2]][T[3]]][k],dp[i][j][k]+1);
				}
				if (vis[j][k]){
					Vi T=A[j];
					int c=0;
					For(w,0,4) if (T[w]==k) T[w]=0,c++;
					sort(T.begin(),T.end());
					upd(dp[i][id[T[0]][T[1]][T[2]][T[3]]][k],dp[i][j][k]+c);
				}
			}
		}
	}
	int ans=(1<<30)-1;
	For(i,1,10) upd(ans,dp[n][0][i]);
	printf("%d\n",ans);
}