// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL f( LL a, LL b, char op ) {
	if ( op=='*' ) return a*b;
	if ( op=='+' ) return a+b;
	puts("QQ");
	return -1;	
}
int main()
{
	LL s[4],a,b,c,d,ans=999999999999999LL;
	char x,y,z;
	scanf("%I64d%I64d%I64d%I64d %c %c %c",s,s+1,s+2,s+3,&x,&y,&z);
	sort(s,s+4);
	do {
		a=s[0];
		b=s[1];
		c=s[2];
		d=s[3];
		ans=min(ans,f(f(a,b,x),f(c,d,y),z));
		ans=min(ans,f(f(a,c,x),f(b,d,y),z));
		ans=min(ans,f(f(a,d,x),f(b,c,y),z));
		ans=min(ans,f(f(f(a,b,x),c,y),d,z));
	} while ( next_permutation(s,s+4) );
	printf("%I64d\n",ans);
	return 0;
}