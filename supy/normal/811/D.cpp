#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
#define N 104
int n,m,X1,Y1;
char s[N][N];
int s1[N*N],s2[N*N],top;
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int dy[10]={1,-1,0,0};
int dx[10]={0,0,-1,1};
bool vis[N][N];
bool dfs(int a, int b) {
	if (s[a][b]=='F') return 1;
	vis[a][b]=1;
	rep(i,0,4) { //!!
		int x=a+dx[i],y=b+dy[i];
		if (x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]!='*'&&!vis[x][y])
			if (dfs(x,y)) {
				s1[++top]=x; s2[top]=y;
				return 1;
			}
	}
	return 0;
}
int lr=-1,ud=-1,x=1,y=1;
inline void Out(char c) {
	printf("%c\n",c);
	fflush(stdout);
}
bool isU() {
	read(X1); read(Y1);
	if (x>1&&x<=n) {
		return (X1==x-1);
	}
	if (x==1) return X1==x;
}
bool isL() {
	read(X1); read(Y1);
	if (y>1&&y<=m) {
		return (Y1==y-1);
	}
	if (y==1) return Y1==y;
}
inline void init() {
	rep(i,0,3) {
		int x1=x+dx[i],y1=y+dy[i];
		if (x1==s1[top]&&y1==s2[top]) {
			if (i<=1) { //lr
				if (lr==-1) {
					Out('L');
					if (isL()) lr=0; else lr=1; 
					//0 not; 1 change
				}
				x=X1; y=Y1;
				if (x+dx[i]==s1[top]&&y+dy[i]==s2[top]) {
					bool P=i^lr;
					if (P==0) Out('R'); else Out('L');
					read(X1); read(Y1);
				}
			}
			else { //ud
				if (ud==-1) {
					Out('U');
					if (isU()) ud=0; else ud=1;
				}
				x=X1; y=Y1;
				if (x+dx[i]==s1[top]&&y+dy[i]==s2[top]) {
					bool P=(i-2)^ud;
					if (P==0) Out('U'); else Out('D');
					read(X1); read(Y1);
				}	
			}
			break;
		}
	}
	x=s1[top]; y=s2[top]; top--;
}
int main()
{
	read(n); read(m);
	rep(i,1,n) scanf("%s",s[i]+1);
	dfs(1,1); //top--;
//	printf("%d\n",top);
//	while (top--) printf("%d %d\n",s1[top+1],s2[top+1]);
	while (top) init();
	return 0;
}