#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int j=x; i>=y; --i)

using namespace std;
const int N=200005;
int n,p[N][4];
multiset <int> s[4];

int getint()
{
	char ch;
	int f=1;	
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int main()
{
	n=getint();
	rep(i,1,n) rep(j,0,3) p[i][j]=getint(),s[j].insert(p[i][j]);
	rep(i,1,n)
	{
		rep(j,0,3) s[j].erase(s[j].find(p[i][j]));
		if(*s[0].rbegin()<=*s[2].begin() && *s[1].rbegin()<=*s[3].begin())
		{
			printf("%d %d\n",*s[0].rbegin(),*s[1].rbegin());
			break;
		}
		rep(j,0,3) s[j].insert(p[i][j]);
	}
	return 0;
}