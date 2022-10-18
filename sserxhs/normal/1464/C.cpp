#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[26],c,n,x,i,s;
ll t;
int main()
{
	scanf("%d%lld",&n,&t);n-=2;c=getchar();
	while (c<'a'||c>'z') c=getchar();c-='a';
	while (n--) ++a[c],t+=1<<c,c=getchar()-'a';
	t+=1<<c;t-=1<<getchar()-'a';
	if (t<0) return puts("No"),0;
	for (i=25;~i;i--)
	{
		x=1<<i+1;
		s=min((ll)a[i],t/x);
		t-=(ll)s*x;
	}
	if (t) puts("No"); else puts("Yes");
}