#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 7005
int n,k[2],s[2][N],dp[2][N]; //1 win  0 loop  -1 lose
int ans[2][N],Degree[2][N]; //From the first place
struct Node {
	int p,turn;
} q[N<<2],u,v;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int getstarter(int x, int y) {
	return (x==1&&y==1||x==-1&&y==0) ? 0 : 1;
} //win/lose + now turn
inline void bfs() {
	int f=0,r=2;
	u.p=1; u.turn=0; q[0]=u; dp[0][1]=-1;
	u.turn=1; q[1]=u; dp[1][1]=-1;
	rep(i,1,n) rep(j,0,1) Degree[j][i]=k[j]; //
	while (f!=r) {
		u=q[f++]; int now=u.turn;
	//	printf("%d %d : ",now,u.p);
		rep(i,1,k[now^1]) { //len!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			int dot=(u.p-s[now^1][i]+n-1)%n+1; //% !!!!!!!!!!
			if (dot==1) continue; //can't be realized!!!!!!!!
		//	printf("<%d>",dot);
			if (dp[now][u.p]==-1) {
				if (dp[now^1][dot]==1) continue;
			//	printf("(%d %d) ",1,dot);
				dp[now^1][dot]=1;
				v.turn=u.turn^1; v.p=dot;
				q[r++]=v;
			//	ans[getstarter(1,u.turn^1)][dot]=1;
			//	ans
			}
			else if (dp[now][u.p]==1) {
			//	if (dp[now^1][dot]==1) continue;    if win,can't lose!!
				if ((--Degree[now^1][dot])==0) {
				//	printf("(%d %d) ",-1,dot);
					dp[now^1][dot]=-1;
					v.turn=u.turn^1; v.p=dot;
					q[r++]=v;
				//	ans[getstarter(-1,u.turn^1)][dot]=-1;
				}
			}
		}
	//	puts("");
	}
}
int main() {
//	freopen("1.in","r",stdin);
	read(n);
	rep(i,0,1) {read(k[i]); rep(j,1,k[i]) read(s[i][j]);}
	bfs();
	rep(i,0,1) {
		rep(j,2,n)
			if (dp[i][j]==1) printf("Win ");
			else if (dp[i][j]==-1) printf("Lose ");
			else printf("Loop ");
		//	printf("%d ",dp[i][j]);
		puts("");
	}
	return 0;
}