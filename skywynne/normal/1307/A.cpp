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
        int d;
        cin >> n >> d;
        for (int i = 1; i <= n; i ++)
            cin >> A[i];
        for (int i = 2; i <= n; i ++)
        {
            while (d >= i - 1 && A[i])
                d -= i - 1, A[1] ++, A[i] --;
        }
        printf("%d\n", A[1]);
    }
    return 0;
}