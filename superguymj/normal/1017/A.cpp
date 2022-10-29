#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1005;
int n,a[N],ans;

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
	rep(i,1,n)
		rep(j,0,3)
			a[i]+=100-getint();
	rep(i,2,n) if(a[i]<a[1]) ++ans;
	printf("%d\n",ans+1);
	return 0;
}