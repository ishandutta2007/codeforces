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

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int t1;
		scanf("%d",&t1);
		if(t1%4==0)
			printf("%d\n",t1/4);
		if(t1%4==1)
		{
			if(t1<9)
				printf("-1\n");
			else
				cout<<(t1-9)/4+1<<endl;
		}
		if(t1%4==2)
		{
			if(t1<6)
				printf("-1\n");
			else
				cout<<(t1-6)/4+1<<endl;
		}		
		if(t1%4==3)
		{
			if(t1<15)
				printf("-1\n");
			else
				cout<<(t1-15)/4+2<<endl;
		}
	}
}