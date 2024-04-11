// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[1000];
	int cnt=0,ans=0;
	while ( gets(s) ) {
		if ( s[0]=='+' ) cnt++;
		else if ( s[0]=='-' ) cnt--;
		else ans+=cnt*strlen(strchr(s,':')+1);
	}
	printf("%d\n",ans);
	return 0;
}