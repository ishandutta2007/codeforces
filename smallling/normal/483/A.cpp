#include<cstdio>

using namespace std;

long long l,r;

int main()
{
    scanf("%I64d%I64d",&l,&r);
    for(long long i=l;i+2<=r;i++)
        if(i%2ll==0)
        {
            printf("%I64d %I64d %I64d",i,i+1,i+2);
            return 0;
        }
    puts("-1");
}