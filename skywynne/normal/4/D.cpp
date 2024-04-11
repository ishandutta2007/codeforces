#include<bits/stdc++.h>
#define f first
#define s second.f
#define t second.second
using namespace std;
int n, r, dp[5010], T[5010];
pair < int , pair < int , int > > A[5010];
int main()
{
    cin >> n >> A[0].f >> A[0].s;
    r = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[r].f >> A[r].s;
        if (A[r].f > A[0].f && A[r].s > A[0].s)
        {
            A[r ++].t = i;
        }
    }
    sort(A + 1, A + r);
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (A[i].f < A[j].f && A[i].s < A[j].s && dp[i] < dp[j] + 1)
            {
                //cout << " :" << i << ": ";
                dp[i] = dp[j] + 1;
                T[i] = j;
            }
        }
        //cout << i << " " << dp[i] << " " << T[i] << endl;
    }
    cout << dp[0] << endl;
    if (dp[0] != 0)
    {
        for (int i = T[0]; i != 0; i = T[i])
        {
            cout << A[i].t << " ";
        }
    }
    return (0);
}