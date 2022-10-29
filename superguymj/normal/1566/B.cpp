#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
 
using namespace std;
const int N=100005;
char s[N];
int n,cnt;
 
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
	scanf("%s",s+1),n=strlen(s+1),cnt=0;
	rep(i,1,n) if(s[i]=='0' && (i==n || s[i+1]=='1')) ++cnt;
	if(cnt==0) puts("0");
	else if(cnt==1) puts("1");
	else puts("2");
}
 
int main()
{	
	int T=getint();
	while(T--) solve();
	return 0;
}