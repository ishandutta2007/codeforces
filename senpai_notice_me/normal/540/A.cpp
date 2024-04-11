//File: .cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char rd;
int n,num[1005],ans=0,readin;
int main()
{
	cin>>n;
	getchar();
	for (int i=1;i<=n;i++)
	{
	    scanf("%c",&rd);
	    num[i]=rd-'0';
	}
	getchar();
	for (int i=1;i<=n;i++)
	{
	    scanf("%c",&rd);
	    readin=rd-'0';
	    ans+=min((num[i]+10-readin)%10,(readin+10-num[i])%10);
    }
    printf("%d",ans);
	return 0;
}