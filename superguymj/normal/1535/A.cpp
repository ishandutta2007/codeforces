#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int a[4];

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
	int T=getint();
	while(T--)
	{
		rep(i,0,3) a[i]=getint();
		int s1=max(a[0],a[1]),s2=max(a[2],a[3]);
		sort(a,a+4);
		if(s1>s2) swap(s1,s2);
		if(s1==a[2] && s2==a[3]) puts("YES");
		else puts("NO");
	}
	return 0;
}