#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n/4;i++)
        if((n-i*4)%7==0)
        {
            for(int j=0;j<i;j++)putchar('4');
            for(int j=0;j<(n-i*4)/7;j++)putchar('7');
            puts("");
            return 0;
        }
    puts("-1");
    return 0;
}