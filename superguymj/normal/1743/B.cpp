#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid ((l+r)>>1)
#define pb push_back

using namespace std;
int n;

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
	n=getint();
	printf("1");
	rep(i,3,n) printf(" %d",i);
	printf(" 2\n"); 
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}