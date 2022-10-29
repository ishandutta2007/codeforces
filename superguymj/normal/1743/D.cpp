#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)
#define pb push_back

using namespace std;
const int N=1000005;
int n;
char s[N];
bitset <N> f,a,ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void prt(bitset <N> a)
{	
	int p=-1;
	rep(i,0,n-1) if(a[i]) p=i;
	if(p==-1) puts("0");
	else 
	{
		repd(i,p,0) putchar('0'+a[i]);
		puts("");
	}
}

void chkmax(bitset <N> &a,bitset <N> b)
{
	repd(i,n-1,0)
	{
		if(a[i]>b[i]) return;
		if(a[i]<b[i])
		{
			rep(j,0,n-1) a[j]=b[j];
			return;
		}
	}
}

void solve1()
{
	rep(i,1,n) a[n-i]=(s[i]-'0');
	rep(i,0,n)
	{
		f=a|(a>>i);
		chkmax(ans,f);
	}
	prt(ans);
}

void solve2()
{
	rep(i,1,n) a[n-i]=(s[i]-'0');
	int l,r;
	rep(i,1,n) if(s[i]=='1') {l=i; break;}
	rep(i,l,n) if(s[i]=='0') {r=i-1; break;}
	rep(i,0,r-l+1)
	{
		f=a|(a>>i);
		chkmax(ans,f);
	}
	prt(ans);
}

int main()
{
	n=getint();
	scanf("%s",s+1);
	if(n<=1000) solve1();
	else solve2();
	return 0;
}