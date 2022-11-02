#include<bits/stdc++.h>
#define f first
#define s second.f
#define t second.second
using namespace std;
int n, m, Mx, dp[300010];
pair < int , pair < int , int > > A[300010];
vector < pair < int , int > > V;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &A[i].s, &A[i].t, &A[i].f);
    }
    sort(A + 1, A + m + 1);
    reverse(A + 1, A + m + 1);
    A[m + 1] = (make_pair(1e6, make_pair(0, 0)));
    for (int i = 1; i <= m; i++)
    {
        if (dp[A[i].t] + 1 > dp[A[i].s])
        {
            V.push_back(make_pair(A[i].s, dp[A[i].t] + 1));
        }
        if (A[i].f != A[i + 1].f)
        {
            for (int j = 0; j < V.size(); j++)
            {
                dp[V[j].f] = max(dp[V[j].f], V[j].second);
            }
            V.clear();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        Mx = max(Mx, dp[i]);
    }
    cout << Mx;
    return (0);
}