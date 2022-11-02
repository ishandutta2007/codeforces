#include<cstdio>

using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if(n<=3)puts("NO");
    else
    {
        puts("YES");
        if(n==4)
        {
            puts("1 * 2 = 2");
            puts("2 * 3 = 6");
            puts("6 * 4 = 24");
            return 0;
        }
        if(n==5)
        {
            puts("5 - 2 = 3");
            puts("3 + 3 = 6");
            puts("1 * 4 = 4");
            puts("4 * 6 = 24");
            return 0;
        }
        if(n==6)
        {
            puts("2 - 1 = 1");
            puts("3 + 1 = 4");
            puts("5 - 4 = 1");
            puts("4 * 6 = 24");
            puts("24 * 1 = 24");
            return 0;
        }
        if(n&1)
        {
            puts("5 - 2 = 3");
            puts("3 + 3 = 6");
            puts("1 * 4 = 4");
            puts("4 * 6 = 24");
            for(int i=6;i<=n;i+=2)
            {
                printf("%d - %d = %d\n",i+1,i,1);
                puts("24 * 1 = 24");
            }
        }
        else
        {
            puts("2 - 1 = 1");
            puts("3 + 1 = 4");
            puts("5 - 4 = 1");
            puts("4 * 6 = 24");
            puts("24 * 1 = 24");
            for(int i=7;i<=n;i+=2)
            {
                printf("%d - %d = %d\n",i+1,i,1);
                puts("24 * 1 = 24");
            }
        }
    }
}