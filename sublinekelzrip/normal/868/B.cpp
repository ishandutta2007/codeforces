#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
char s[10],a[1000][1100];;
int main()
{
	int h,m,s,t1,t2;
	cin>>h>>m>>s>>t1>>t2;
	int x;
	for(x=t1;x!=t2;x==12?x=1:x++)
	{
		if(x==h)
			break;
		if(x%12==m/5)
			break;
		if(x%12==s/5)
			break;
	}
	if(x==t2)
	{
		printf("YES");
		return 0;
	}
	for(x=t2;x!=t1;x==12?x=1:x++)
	{
		if(x==h)
			break;
		if(x%12==m/5)
			break;
		if(x%12==s/5)
			break;
	}
	if(x==t1)
	{
		printf("YES");
		return 0;
	}
	printf("NO");
}