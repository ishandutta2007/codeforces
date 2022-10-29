#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=4005;
int n;
int a[N],b[N],bn;
int f[N][N];

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d",&n);
		rep(i,1,n*2) scanf("%d",&a[i]);
		bn=0;
		rep(i,1,n*2)
		{
			int j=i;
			while(j<=n*2 && a[i]>=a[j]) ++j;
			--j,b[++bn]=j-i+1,i=j;
		}
		f[0][0]=1;
		rep(i,1,bn)
			rep(j,0,n*2) if(f[i-1][j])
			{
				f[i][j]=1;
				f[i][j+b[i]]=1;
			}

		if(f[bn][n]) puts("YES");
		else puts("NO");
		
		rep(i,0,bn) rep(j,0,2*n) f[i][j]=0;
	}
	
	return 0;
}