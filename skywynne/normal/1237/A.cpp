// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 74;
int n, q, A[N];
int main()
{
    scanf("%d", &n);
    int odd = 0;
    for (int i = 0; i < n; i ++)
    {
        int a;
        scanf("%d", &a);
        if (a % 2 == 0)
        {
            printf("%d\n", a / 2);
            continue;
        }
        if (odd == 0)
            printf("%d\n", (a - 1) / 2), odd = 1;
        else
            printf("%d\n", (a + 1) / 2), odd = 0;
    }
    return 0;
}