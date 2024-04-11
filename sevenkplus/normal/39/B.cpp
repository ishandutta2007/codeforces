#include <cstdio>

#define maxN 101

using namespace std;

int n, a[maxN];

int main()
{
    scanf("%d", &n);
    int m = 0;
    for(int i = 1; i <= n; ++ i)
    {
        scanf("%d", a + i);
        if(a[i] == (m + 1))
            m ++;
    }
    printf("%d\n", m);
    if(m)
    {
        m = 0;
        for(int i = 1; i <= n; ++ i)
            if(a[i] == (m + 1))
            {                
                m ++;
                if(m > 1)
                    printf(" ");
                printf("%d", 2000 + i);
            }
        printf("\n");
    }
    return 0;
}