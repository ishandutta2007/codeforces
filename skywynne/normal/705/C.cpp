#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int MXN = 3e5 + 10;
int n, q, r, t, p, c, ts;
set < int > A[MXN];
set < pair < int , int > > S;
int main()
{
    scanf("%d%d", &n, &q);
    while (q --)
    {
        scanf("%d%d", &t, &r);
        if (t == 1)
        {
            A[r].insert(++ ts);
            S.insert(make_pair(ts, r));
        }
        if (t == 2)
        {
            for (auto X : A[r])
                S.erase(make_pair(X, r));
            A[r].clear();
        }
        if (t == 3)
        {
            for (auto X : S)
            {
                if (X.x > r)
                    break;
                A[X.y].erase(X.x);
            }
            auto it = S.upper_bound({r, 1e9});
            S.erase(S.begin(), it);
        }
        printf("%d\n", (int)S.size());
    }
    return (0);
}