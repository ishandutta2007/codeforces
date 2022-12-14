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
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int main()
{
	int k;
	cin>>k;
	if(k==0)
	{
	puts("abc");return 0;}
	char a='a';
	while(k)
	{
		int x=1;
		while((x+1)*1ll*x/2<=k)
			x++;
		for(int i=1;i<=x;i++)
			putchar(a);
		k-=x*1ll*(x-1)/2;
		a++;
	}
}