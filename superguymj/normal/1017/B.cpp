#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
int n,cnt[10];
char a[100005],b[100005];
LL ans;

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
	scanf("%s",a+1);
	scanf("%s",b+1);
	rep(i,1,n) ++cnt[((b[i]=='1')<<1)|(a[i]=='1')];
	rep(i,0,3)
		rep(j,0,3)
		{
			bool a1=i&1,a2=j&1;
			bool b1=i&2,b2=j&2;
			if((a1|b1)!=(a2|b1) || (a2|b2)!=(a1|b2)) ans+=(LL)cnt[i]*cnt[j];
		}
	printf("%lld\n",ans/2);
	return 0;
}