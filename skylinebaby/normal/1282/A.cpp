#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x, y, c, r;
        scanf("%d %d %d %d", &x, &y, &c, &r);
        if(x > y) swap(x, y);
        int a = max(x, c - r);
        int b = min(y, c + r);
        printf("%d\n", y - x - max(0, (b - a)));
    }
    return 0;
}