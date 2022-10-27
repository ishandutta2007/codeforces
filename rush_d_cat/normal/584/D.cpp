#include <iostream>
using namespace std;
int n;
bool isprime(int x)
{
    if(x==2) return 1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}
int main()
{
    cin >> n;
    int tmp;
    tmp = n;
    while(true)
    {
        if(isprime(tmp))
        {
            if(tmp == n)
            {
                printf("1\n");
                printf("%d\n", n);
                return 0;
            }
            if(isprime(n-tmp))
            {
                printf("2\n");
                printf("%d %d\n", tmp, n-tmp);
                return 0;
            }
            if((n-tmp)%2)
            {
                if(isprime(n-tmp-2))
                {
                    printf("3\n");
                    printf("%d %d %d\n", 2, n-tmp-2, tmp);
                    return 0;
                }
            } else {
                break;
            }
        }
        tmp --;
    }
    n -= tmp;
    for(int i=2;i<=n-2;i++)
    {
        if(isprime(i) && isprime(n-i))
        {
            printf("3\n");
            printf("%d %d %d\n", tmp, i, n-i);
            return 0;
        }
    }
}