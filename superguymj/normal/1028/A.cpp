#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int j=x; i>=y; --i)

using namespace std;
const int N=120;
int n,m;
char s[N][N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) scanf("%s",s[i]+1);
	
	rep(i,1,m)
	{
		bool jdg=0;
		rep(j,1,n) if(s[j][i]=='B') jdg=1;
		if(jdg)
		{
			int l,r;
			rep(j,1,n) if(s[j][i]=='B') r=j;
			repd(j,n,1) if(s[j][i]=='B') l=j;
			printf("%d ",r+l>>1);
			break;
		}
	}

	rep(i,1,n)
	{
		bool jdg=0;
		rep(j,1,m) if(s[i][j]=='B') jdg=1;
		if(jdg) 
		{
			int l,r;
			rep(j,1,m) if(s[i][j]=='B') r=j;
			repd(j,m,1) if(s[i][j]=='B') l=j;
			printf("%d\n",r+l>>1);
			break;
		}
	}
	return 0;
}