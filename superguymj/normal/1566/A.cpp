#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
 
using namespace std;
 
int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}
 
void solve()
{
	int n=getint(),s=getint();
	printf("%d\n",s/((n+2)>>1));
}
 
int main()
{	
	int T=getint();
	while(T--) solve();
	return 0;
}