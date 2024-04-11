#include<stdio.h>
#include<cstring>

#define mo 1000000007

using namespace std;

char s[100010];
int len;

long long GetAns()
{
    long long nowans=0,suma2=0,suma=0,ak=0,k=1,a1=0;
    scanf("%s",s+1);
    len=strlen(s+1);
    for(int i=1;i<=len;i++)
        if(s[i]=='4')
        {
            nowans=(100*nowans%mo+100*suma2%mo+220*suma%mo+70*(ak-a1+mo)%mo+56*(k-1)%mo)%mo;
            suma2=(200*suma2%mo+220*suma%mo+65*(k-1+mo)%mo)%mo;
            suma=(suma*10*2%mo+11*(k-1+mo)%mo)%mo;
            k=((k-1+mo)*2+1)%mo;
            a1=(10*a1+4)%mo;
            ak=(ak*10+4)%mo;
        }
        else
        {
            nowans=(100*nowans%mo+100*suma2%mo+220*suma%mo+70*(ak-a1+mo)%mo+56*(k-1)%mo+(ak*10+4)%mo*(ak*10%mo+7)%mo)%mo;
            suma2=(200*suma2%mo+220*suma%mo+65*(k-1+mo)%mo+(ak*10+4)%mo*(ak*10%mo+4)%mo)%mo;
            suma=(suma*10*2%mo+11*(k-1+mo)%mo+ak*10%mo+4)%mo;
            k=((k-1+mo)*2+2)%mo;
            a1=(10*a1+4)%mo;
            ak=(ak*10+7)%mo;            
        }
    return nowans;
}

int main()
{
    long long ans=(-GetAns()+mo)%mo;
    (ans+=GetAns())%=mo;
    printf("%I64d",ans);
}