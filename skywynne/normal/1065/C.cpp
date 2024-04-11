#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 2e5 + 10, Mod = 1e9 + 7;
int n, m, k, A[N], C[N];
int main()
{
    m = N;
    int mx = -1;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]), m = min(m, A[i]), mx = max(mx, A[i]), C[A[i]] ++;
    if (m == mx) return !printf("0");
    for (int i = N - 2; ~i; i--)
        C[i] += C[i + 1];
    long long c = 0;
    int tot = 1;
    for (int i = N - 1; i >= m + 1; i--)
    {
        if (c + C[i] > k)
        {
            tot ++;
            c = 0;
        }
        c += C[i];
    }
    printf("%d\n", tot);
    return (0);
}