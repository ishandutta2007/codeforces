#include<stdio.h>
#include<cstring>
using namespace std;
char str[105];
long sumx[105],sumy[105];
long len;
long x,y;long a,b;
int main()
{
    scanf("%ld%ld",&a,&b);
    scanf("%s",str+1);len=strlen(str+1);
    sumx[0]=sumy[0]=0;
    if(a==0&&b==0)
    {
        printf("Yes\n");
        return 0;
    }
    for(long i=1;i<=len;i++)
    {
        sumx[i]=sumx[i-1];
        sumy[i]=sumy[i-1];
        if(str[i]=='U')sumy[i]++;
        if(str[i]=='R')sumx[i]++;
        if(str[i]=='L')sumx[i]--;
        if(str[i]=='D')sumy[i]--;
    }
    for(long i=1;i<=len;i++)
    {
        long a1=a-sumx[i];
        long b1=b-sumy[i];
        long t1=0,t2=0;
        if(sumx[len]==0&&a1!=0)continue;
        if(sumy[len]==0&&b1!=0)continue;
        bool flag1=false,flag2=false;
        if(sumx[len]==0&&a1==0)flag1=true;
        if(sumy[len]==0&&b1==0)flag2=true;
        if(a1==0&&b1==0)
        {
            printf("Yes\n");
            return 0;
        }
        if(flag1&&flag2)
        {
            printf("Yes\n");
            return 0;
        }
        if(flag1)
        {
            if(b1==0)
            {
                printf("Yes\n");
                return 0;
            }
            else
            if(sumy[len]!=0)
            if((b1%sumy[len]==0)&&(sumy[len]!=0&&b1/sumy[len]>=0))
            {
                printf("Yes\n");
                return 0;
            }
            else continue;
        }
        if(flag2)
        {
            if(a1==0)
            {
                printf("Yes\n");
                return 0;
            }
            else
            if(sumx[len]!=0)
            if((a1%sumx[len]==0)&&(sumx[len]!=0&&a1/sumx[len]>=0))
            {
                printf("Yes\n");
                return 0;
            }
            else continue;
        }
        if(a1%sumx[len])continue;
        if(b1%sumy[len])continue;
        t1=a1/sumx[len];
        t2=b1/sumy[len];
        if(t1==t2&&t1>=0)
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}