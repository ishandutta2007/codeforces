//file: .cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,l,readin,fan[1000005];
char s[1000005],t;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(fan,0,sizeof(fan));
	scanf("%s",s+1);
	l=strlen(s+1);
    cin>>n;
	for(int i=1;i<=n;i++)
	{
	    scanf("%d",&readin);
	    if(readin>(l/2))
	        readin=l-readin+1;
	    fan[readin]^=1;
    }
    for(int i=1;i<=(l/2);i++)
    {
        if(fan[i]==1)
        {
            t=s[i];
            s[i]=s[l-i+1];
            s[l-i+1]=t;
            fan[i+1]^=1;
        }
    }
    printf("%s",s+1);
	File_end:
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}