#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
int n;
LL a[100005],b[100005],tot,ans;

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
	rep(i,1,n) a[i]=getint(),tot+=a[i];
	rep(i,1,n) b[i]=getint();
	sort(b+1,b+1+n);
	ans=b[n]+b[n-1];
	if(ans>=tot) puts("YES");
	else puts("NO");
	return 0;
}