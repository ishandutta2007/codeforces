#include<cstdio>

using namespace std;

int o,bo,sum[100];

int main()
{
    for(int i=1;i<=6;i++)
        scanf("%d",&o),sum[o]++;
    bo=0;
    for(int i=1;i<=9;i++)
        if(sum[i]>=4)bo=1;
    if(!bo)return puts("Alien"),0;
    for(int i=1;i<=9;i++)
        if((sum[i]==1||sum[i]==5))return puts("Bear"),0;
        else if(sum[i]==2||sum[i]==6)return puts("Elephant"),0;
}