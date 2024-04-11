// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1, b1, c1, d1;
    int a2, b2, c2, d2;
    scanf("%d%d%d%d", &a1, &c1, &b1, &d1);
    for (int w = 0; w <= 1; w ++)
    {
        scanf("%d%d%d%d", &a2, &c2, &b2, &d2);
        if (a2 <= a1 && b1 <= b2 && c2 <= c1)
            c1 = max(c1, d2);
        if (a2 <= a1 && b1 <= b2 && d1 <= d2)
            d1 = min(d1, c2);
        if (c2 <= c1 && d1 <= d2 && a2 <= a1)
            a1 = max(a1, b2);
        if (c2 <= c1 && d1 <= d2 && b1 <= b2)
            b1 = min(b1, a2);
        if (b1 <= a1 || d1 <= c1)
            return puts("NO");
    }
    return puts("YES");
}