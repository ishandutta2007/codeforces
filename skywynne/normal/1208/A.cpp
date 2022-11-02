// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 74;
int q, n, A[N];
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        int a, b;
        scanf("%d%d%d", &a, &b, &n);
        if (n % 3 == 0) printf("%d\n", a);
        if (n % 3 == 1) printf("%d\n", b);
        if (n % 3 == 2) printf("%d\n", a ^ b);
    }
    return 0;
}