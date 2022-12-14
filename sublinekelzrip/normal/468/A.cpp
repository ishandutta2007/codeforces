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
int main()
{
	int n;
	cin>>n;
	if(n<4)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if(n%2)
	{
		cout<<"YES"<<endl;
		printf("5 - 2 = 3\n3 + 3 = 6\n6 * 1 = 6\n6 * 4 = 24\n");
		for(int n1=6;n1<=n;n1+=2)
			printf("%d - %d = 1\n24 * 1 = 24\n",n1+1,n1);
	}
	else
	{
		cout<<"YES"<<endl;
		printf("1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
		for(int n1=5;n1<=n;n1+=2)
			printf("%d - %d = 1\n24 * 1 = 24\n",n1+1,n1);
	}
}