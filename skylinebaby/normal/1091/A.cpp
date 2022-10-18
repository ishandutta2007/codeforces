#include<bits/stdc++.h>
using namespace std;
int t[12345];
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	a++;c--;
	int ans = min(a,b);
	ans = min(ans,c);
	printf("%d\n",3*ans);
	return 0;
}