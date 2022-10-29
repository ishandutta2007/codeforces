#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
char s[55];
int n,T;

void solve()
{
	scanf("%s",s+1),n=strlen(s+1);
	int l=1,r;
	while(l<=n)
	{
		r=l;
		while(r+1<=n && s[r+1]==s[r]) ++r;
		if(l==r) {puts("NO"); return;}
		l=r+1;
	}
	puts("YES");
}

int main()
{
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}