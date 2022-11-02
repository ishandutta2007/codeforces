// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
int main()
{
	char a[N],b[N];
	scanf("%[^.].%s",a,b);
	int La=strlen(a);
	if ( a[La-1]=='9' ) puts("GOTO Vasilisa.");
	else if ( b[0]<'5' ) puts(a);
	else {
		a[La-1]++;
		puts(a);
	}
	return 0;
}