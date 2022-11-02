#include<bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, C[3];
char A[N];
inline void Go(int a, int b)
{
    if (a < b)
        for (int i = 0; i < n && C[a] * 3 < n; i++)
            if (A[i] == b + '0' && C[b] * 3 > n)
                A[i] = a + '0', C[a] ++, C[b] --;
    if (a > b)
        for (int i = n - 1; i >= 0 && C[a] * 3 < n; i--)
            if (A[i] == b + '0' && C[b] * 3 > n)
                A[i] = a + '0', C[a] ++, C[b] --;
}
int main()
{
    scanf("%d%s", &n, &A);
    for (int i = 0; i < n; i++)
        C[A[i] - '0'] ++;
    Go(0, 1); Go(0, 2);
    Go(1, 2); Go(2, 1);
    Go(2, 0); Go(1, 0);
    return !printf("%s", A);
}