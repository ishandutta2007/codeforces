#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<algorithm>
using namespace std;

inline bool isdigit(char c) {return c>='0'&&c<='9';}

inline int read() {
	int res=0,f=1;char ch;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	do {
		res=res*10+ch-'0';
	} while(isdigit(ch=getchar()));
	return res*f;
}

const int N=505;

int T,n,m,ans[N][N];

int dx[8]={-1,0,1,1,1,0,-1,-1},dy[8]={1,1,1,0,-1,-1,-1,0};

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1 ; i<=n+1 ; ++i)
			for(int j=1 ; j<=m+1 ; ++j)
				ans[i][j]=0;
		ans[1][1]=ans[1][m]=ans[n][1]=ans[n][m]=1;
		for(int i=1 ; i<=n ; ++i)
			for(int j=1 ; j<=m ; ++j) {
				if(i==1||i==n||j==1||j==m) {
					bool ck=1;
					for(int k=0 ; k<8 ; ++k)
						ck&=!ans[i+dx[k]][j+dy[k]];
					if(ck) ans[i][j]=1;
				}
			}
		for(int i=1 ; i<=n ; ++i,puts(""))
			for(int j=1 ; j<=m ; ++j)
				printf("%d",ans[i][j]);
	}
	return 0;
}