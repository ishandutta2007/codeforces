#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char Home[101],Away[101],Team,Card;
int N,foulH[101],foulA[101],t,num;
int main()
{
    scanf("%s%s",Home,Away);
	cin>>N;
	for(int i=1;i<=N;i++)
	{
	    scanf("%d%c%c%d%c%c",&t,&Team,&Team,&num,&Card,&Card);
	    if(Team=='h')
	    {
	        if(foulH[num]<2)
	        {
	            foulH[num]++;
	            if(Card=='r')
	                foulH[num]++;
	            if(foulH[num]>=2)
	                printf("%s %d %d\n",Home,num,t);
            }
        }
        else
        {
            if(foulA[num]<2)
            {
                foulA[num]++;
                if(Card=='r')
                    foulA[num]++;
                if(foulA[num]>=2)
                    printf("%s %d %d\n",Away,num,t);
            }
        }
    }
	return 0;
}