#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

long long n,readin,tech[3],last,ft1,ft2;
queue<long long>fir,sec;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    scanf("%I64d",&readin);
	    if(readin>0)
	    {
	        last=1;
	        tech[1]+=readin;
	        fir.push(readin);
	    }
	    else
	    {
	        last=2;
	        tech[2]-=readin;
	        sec.push(-readin);
	    }
    }
    if(tech[1]>tech[2])
        printf("first");
    else if(tech[1]<tech[2])
        printf("second");
    else
    {
        while(!fir.empty() && !sec.empty())
        {
            ft1=fir.front(),ft2=sec.front();
            if(ft1>ft2)
            {
                printf("first");
                goto File_end;
            }
            else if(ft1<ft2)
            {
                printf("second");
                goto File_end;
            }
            fir.pop(),sec.pop();
        }
        if(!fir.empty() && sec.empty())
            printf("first");
        else if(fir.empty() && !sec.empty())
            printf("second");
        else if(fir.empty() && sec.empty())
            if(last==1)
                printf("first");
            else
                printf("second");
    }
    File_end:
	return 0;
}