#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10;
int n, m, k, A[N], Tp[N];
vector < int > OP;
vector < pair < int , int > > Q[N][2];
vector < pair < pair < int , int > , int > > F;
bool CMP(pair < pair < int , int > , int > X, pair < pair < int , int > , int > Y) {return ((long double)X.x.x * Y.x.y > (long double)X.x.y * Y.x.x);}
bool CMP2(int i, int j) {return (Tp[i] < Tp[j]);}
int32_t main()
{
    scanf("%lld%lld%lld", &k, &n, &m);
    for (int i = 1; i <= k; i++)
        scanf("%lld", &A[i]);
    for (int i = 1, id, b; i <= n; i++)
    {
        scanf("%lld%lld%lld", &Tp[i], &id, &b);
        if (Tp[i] != 3)
            Q[id][Tp[i] - 1].pb({b, i});
        else
            F.pb({{b, 1}, i});
    }
    for (int i = 1; i <= k; i++)
        if (Q[i][0].size())
        {
            sort(Q[i][0].begin(), Q[i][0].end());
            if (Q[i][0].back().x > A[i])
                Q[i][1].pb({Q[i][0].back().x - A[i], Q[i][0].back().y});
        }
    for (int i = 1; i <= k; i++)
        if (Q[i][1].size())
        {
            int sum = A[i];
            sort(Q[i][1].begin(), Q[i][1].end());
            reverse(Q[i][1].begin(), Q[i][1].end());
            for (auto X : Q[i][1])
                F.pb({{X.x + sum, sum}, X.y}), sum += X.x;
        }
    sort(F.begin(), F.end(), CMP);
    for (int i = 0; i < m && i < F.size(); i++)
        OP.pb(F[i].y);
    sort(OP.begin(), OP.end(), CMP2);
    printf("%lld\n", (int)OP.size());
    for (int op : OP)
        printf("%lld ", op);
    return (0);
}