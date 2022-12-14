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
	scanf("%s",s);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]==s[0]&&a[i][1]==s[1])
			ans=1;
		for(int j=1;j<=n;j++)
			if(a[i][1]==s[0]&&a[j][0]==s[1])
				ans=1;
	}
	if(ans)
		printf("YES");
	else
		printf("NO");
}