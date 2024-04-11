#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid ((l+r)>>1)

using namespace std;
const int N=205;
char s[N];
int n,m,k,cnt[30];

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
	rep(i,0,24) cnt[i]=0;
	n=getint(),k=getint(),m=n/k;
	scanf("%s",s+1);
	rep(i,1,n) ++cnt[s[i]-'a'];
	rep(i,1,k)
	{
		rep(j,0,25) if(!cnt[j] || j==m)
		{
			putchar('a'+j);
			rep(x,0,j-1) --cnt[x];
			break;
		}
	}
	puts("");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}