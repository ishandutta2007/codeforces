#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

char s[1000005];
int n,l,r;
int a[1000005];
char ch;

int main()
{
	scanf("%s",s);
	n=strlen(s);
	memset(a,0,sizeof(a));
	l=1,r=n;
	for (int i=1;i<=n;i++)
	{
		ch=s[i-1];
		if (ch=='l') a[l]=i,++l; else a[r]=i,--r;
	}
	for (int i=n;i>=1;i--) printf("%d\n",a[i]);
    
    return 0;
}