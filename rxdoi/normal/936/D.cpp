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

const int N=4e6+19;
const int oo=(1<<30)-1;

map<pii,int> M;
int dp[2][N],pre[2][N],A[2][N];
int x[N],x1[N],x2[N];
int n,m1,m2,t,m,w,las;

void upd(int i,int j,int y,int z){
	if (y>dp[i][j]){
		dp[i][j]=y;
		pre[i][j]=z;
	}
}

int main(){
	n=IN();m1=IN(),m2=IN(),t=IN();
	For(i,1,m1+1){
		x1[i]=IN();
		M[mp(0,x1[i])]=1;
		x[++m]=x1[i];
		x[++m]=x1[i]+1;
	}
	For(i,1,m2+1){
		x2[i]=IN();
		M[mp(1,x2[i])]=1;
		x[++m]=x2[i];
		x[++m]=x2[i]+1;
	}
	x[++m]=1;
	x[++m]=n+1;
	sort(x+1,x+m+1);
	m=unique(x+1,x+m+1)-x-1;
	For(i,1,m1+1){
		A[0][lower_bound(x,x+m+1,x1[i])-x]=1;
	}
	For(i,1,m2+1){
		A[1][lower_bound(x,x+m+1,x2[i])-x]=1;
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=dp[1][0]=0;
	pre[1][0]=1;
	For(i,0,m){
		For(w,0,2) if (~dp[w][i]&&!A[w^1][i]) upd(w^1,i,min(dp[w][i],t),1);
		For(w,0,2) if (~dp[w][i]&&dp[w][i]+x[i+1]-x[i]-1>=t*A[w][i+1]){
			upd(w,i+1,dp[w][i]+x[i+1]-x[i]-t*A[w][i+1],0);
		}
	}
	w=(dp[0][m]>dp[1][m]?0:1);
	if (dp[w][m]==-1){
		puts("No");
	} else{
		puts("Yes");
		Vi A;
		vector<pii> B;
		las=oo;
		for (int i=w,j=m;i||j;){
			if (pre[i][j]){
				A.pb(x[j]),i^=1;
			} else{
				if (::A[i][j]){
					las=min(las-t,x[j]-1);
					//while (M.count(mp(i,las))) las--;
					B.pb(mp(las,i+1));
				}
				j--;
			}
		}
		printf("%d\n",A.size());
		for (int i=int(A.size())-1;~i;i--) printf("%d ",A[i]);
		puts("");
		printf("%d\n",B.size());
		for (int i=int(B.size())-1;~i;i--) printf("%d %d\n",B[i].fi,B[i].se);
	}
}