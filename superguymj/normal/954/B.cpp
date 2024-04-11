#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
int n;
char s[1000];

bool check(int x)
{
	rep(i,1,x)
		if(s[i]!=s[x+i])
			return 0;
	return 1;
}

int main()
{
	scanf("%d%s",&n,s+1);
	repd(i,n/2,1)
		if(check(i)) return printf("%d\n",n-i+1),0;
	return printf("%d\n",n),0;
}