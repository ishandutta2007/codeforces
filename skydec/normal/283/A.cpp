#include<stdio.h>
#include<cstring>
#define MAXN 210000
using namespace std;
typedef long long LL;
LL add[MAXN];
LL val[MAXN];
LL sum,number;int n,m;
int main()
{
    scanf("%d",&n);
    number=1;sum=0;
    for(int i=1;i<=n;i++)
    {
            int kind;scanf("%d",&kind);
            if(kind==1)
            {
                       LL a,x;scanf("%I64d%I64d",&a,&x);
                       if(a>number)a=number;
                       add[a]+=x;
                       sum+=a*x;
                       }
            else if(kind==2)
            {
                 LL k;scanf("%I64d",&k);
                 number++;sum+=k;val[number]=k;
                 }
            else
            {
                if(number>=2){
                LL u=val[number];
                u+=add[number];
                add[number-1]+=add[number];
                add[number]=0;
                sum-=u;number--;}
                }
            printf("%.7lf\n",sum*1./number);
            }
    return 0;
}