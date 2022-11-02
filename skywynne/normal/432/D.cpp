#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, l, r, Z[N], C[N];
char A[N];
vector < pair < int , int > > R;
int main()
{
    scanf("%s", &A);
    n = Z[0] = strlen(A);
    for (int i = 1; i < n; i++)
    {
        if (r <= i)
        {
            l = i; r = i;
            while (r < n && A[r] == A[r - l])
                r ++;
            Z[i] = r - l;
            continue;
        }
        if (Z[i - l] < r - i)
            Z[i] = Z[i - l];
        else
        {
            l = i;
            while (r < n && A[r] == A[r - l])
                r ++;
            Z[i] = r - l;
        }
    }
    for (int i = 0; i < n; i++)
        C[Z[i]] ++;
    for (int i = n; ~i; i--)
        C[i] += C[i + 1];
    for (int i = 1; i <= n; i++)
        if (Z[n - i] == i)
            R.push_back({i, C[i]});
    printf("%d\n", (int)R.size());
    for (auto X : R)
        printf("%d %d\n", X.first, X.second);
}