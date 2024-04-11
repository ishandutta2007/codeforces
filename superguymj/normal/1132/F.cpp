#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=505,INF=100000;
char s[N];
int n,f[N][N];

void chkmin(int &x,int y)
{
	x=min(x,y);
}

int main()
{
	scanf("%d%s",&n,s+1);
	rep(i,1,n) rep(j,1,n) f[i][j]=INF;
	rep(i,1,n) f[i][i]=1;
	rep(i,2,n)
		rep(j,1,n-i+1)
			rep(k,j,j+i-2)
				chkmin(f[j][j+i-1],f[j][k]+f[k+1][j+i-1]-(int)(s[k]==s[j+i-1]));
	printf("%d\n",f[1][n]);
	return 0;
}