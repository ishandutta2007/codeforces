#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b, c, n;
        scanf("%d %d %d %d", &a, &b, &c, &n);
        int sum = a + b + c + n;
        int x = sum / 3;
        if(x * 3 != sum) printf("NO\n");
        else
        {
            if(x >= a && x >= b && x >= c) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}