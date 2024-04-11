#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=105;
typedef long long LL;
int n;
char s[N],t[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

bool check()
{
	rep(i,1,n) if(s[i]=='1' && t[i]=='1') return 0;
	return 1;
}

int main()
{
	int T=getint();
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		if(check()) puts("YES");
		else puts("NO");
	}
	return 0;
}