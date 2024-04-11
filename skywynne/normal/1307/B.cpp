// Skywynne
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, A[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q;
    for (; q; q --)
    {
        int n, X;
        cin >> n >> X;
        int Mn = 1e9;
        int Mx = -1;
        for (int i = 1; i <= n; i ++)
        {
            cin >> A[i];
            if (X == A[i])
                Mn = 1;
            Mx = max(Mx, A[i]);
        }
        int ans = X / Mx;
        if (X % Mx)
            ans ++;
        ans = max(ans, 2);
        Mn = min(Mn, ans);
        printf("%d\n", Mn);
    }
    return 0;
}