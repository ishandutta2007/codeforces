#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=1005;
int n,k,a[N][30],b[30];
LL bin[30],cnt[N],ans;
map <LL,int> mp;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

LL get(int a[])
{
	LL ret=0;
	rep(i,1,k) ret+=bin[i-1]*a[i];
	return ret;
}

int main()
{
	n=getint(),k=getint();
	bin[0]=1;
	rep(i,1,k-1) bin[i]=bin[i-1]*3;
	rep(i,1,n)
	{
		rep(j,1,k)
			a[i][j]=getint();
	
		LL s=get(a[i]);
		mp[s]=i;
	}
	rep(i,1,n)
		rep(j,i+1,n)
		{
			rep(x,1,k) b[x]=(6-a[i][x]-a[j][x])%3;
			LL s=get(b);
			if(mp.count(s)) ++cnt[mp[s]];
		}
	rep(i,1,n)
		ans+=(LL)cnt[i]*(cnt[i]-1)/2;
	printf("%lld\n",ans);
	return 0;
}