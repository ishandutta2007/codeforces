#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int j=x; i>=y; --i)

using namespace std;

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
	rep(i,1,2000) printf("5");
	puts("");
	rep(i,1,2000-1) printf("4");
	puts("5"); 
	return 0;
}