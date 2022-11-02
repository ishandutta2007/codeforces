// I'm back b*tches
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, b;
int main()
{
    string A;
    cin >> A;
    n = (int)A.size();
    for (int i = 1; i < n; i++)
    {
        if (n % 2 == 0)
            b |= (A[i] != A[i - 1]);
        else if (i != (n >> 1) && i - 1 != (n >> 1))
            b |= (A[i] != A[i - 1]);
    }
    if (!b) return !printf("Impossible\n");
    for (int i = 1; i < n; i++)
    {
        string B = A.substr(0, i);
        string C = A.substr(i, n - i);
        C += B;
        bool w = 0;
        for (int j = 0; j < n; j++)
            if (C[j] != C[n - j - 1])
                w = 1;
        if (!w && C != A) return !printf("1\n");
    }
    printf("2\n");
    return (0);
}