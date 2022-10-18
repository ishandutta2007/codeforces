#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int h, m;
        scanf("%d %d", &h, &m);
        int x = h % m;
        if(x > m / 2)
        {
            printf("%d\n", h - x + m / 2);
        }
        else printf("%d\n", h);
    }
    return 0;
}