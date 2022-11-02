// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string,int> app;
int main()
{
	int n,t;
	char s[50];
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%s",s);
		t=app[s]++;
		if ( t==0 ) puts("OK");
		else printf("%s%d\n",s,t);
	}
	return 0;
}