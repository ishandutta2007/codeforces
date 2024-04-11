#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template < typename T >
using ordered_set = tree < T , null_type , greater < T > , rb_tree_tag , tree_order_statistics_node_update >;
const int N = 100005;
int n, k, X[N], R[N], F[N], P[N];
long long tot;
ordered_set < int > S[N];
set < pair < int , int > > A;
inline bool CMP(int i, int j)
{
    return (X[i] < X[j]);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &X[i], &R[i], &F[i]), F[i] += 19, P[i] = i;
    sort(P + 1, P + n + 1, CMP);
    for (int h = 1; h <= n; h++)
    {
        int &i = P[h];
        while (A.size() && A.begin()->first < X[i])
            S[F[A.begin()->second]].erase(X[A.begin()->second]), A.erase(A.begin());
        for (int j = F[i] - k; j <= F[i] + k; j++)
            tot += S[j].order_of_key(X[i] - R[i] - 1);
        S[F[i]].insert(X[i]);
        A.insert({X[i] + R[i], i});
    }
    return !printf("%lld", tot);
}