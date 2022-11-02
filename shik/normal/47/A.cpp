// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool ok[1000];
int main()
{
	for ( int i=1; i*(i+1)/2<1000; i++ ) ok[i*(i+1)/2]=1;
	int n;
	scanf("%d",&n);
	puts(ok[n]?"YES":"NO");
	return 0;
}