// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
char s1[N],s2[N],a[110],b[110];
const char sol[4][20]={"fantasy","forward","backward","both"};
int main()
{
	int ans=0;
	scanf("%s %s %s",s1,a,b);
	strcpy(s2,s1);
	reverse(s2,s2+strlen(s2));
	if ( strstr(s1,a) && strstr(s1,a)+strlen(a)<s1+strlen(s1) && strstr(strstr(s1,a)+strlen(a),b) ) ans|=1;
	if ( strstr(s2,a) && strstr(s2,a)+strlen(a)<s2+strlen(s2) && strstr(strstr(s2,a)+strlen(a),b) ) ans|=2;
	puts(sol[ans]);
	return 0;
}