#include<cstdio>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int min=(n+1)/2,max=n;
    for(int i=min;i<=max;i++)
        if(i%m==0)
        {
            printf("%d",i);
            return 0;
        }
    puts("-1");
}