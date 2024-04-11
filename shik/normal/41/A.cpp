// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[200],t[200];
	scanf("%s %s",s,t);
	reverse(s,s+strlen(s));
	puts(strcmp(s,t)==0?"YES":"NO");
	return 0;
}