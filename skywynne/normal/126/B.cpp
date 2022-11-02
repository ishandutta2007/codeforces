#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int n, l, r, Z[N], M[N];
char A[N];
int main()
{
    scanf("%s", &A);
    n = Z[0] = strlen(A);
    for (int i = 1; i < n; i++)
    {
        if (Z[i - l] < r - i)
        {
            Z[i] = Z[i - l];
            continue;
        }
        l = i; r = max(r, i);
        while (r < n && A[r] == A[r - l])
            r ++;
        Z[i] = r - l;
    }
    for (int i = 1; i < n - 1; i++)
        M[Z[i] - (i + Z[i] == n)] ++;
    for (int i = n; i; i--)
        M[i] |= M[i + 1];
    for (int i = n; i; i--)
        if (M[i] && Z[n - i] == i)
            return !printf("%s", A + n - i);
    return !printf("Just a legend");
}