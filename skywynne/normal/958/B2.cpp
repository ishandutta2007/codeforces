#include<bits/stdc++.h>
#define x first
#define y second
#define push_back
using namespace std;
const int N = 1e5 + 10;
int n, m, r, t, R[N], P[N], T[N], A[N];
set < int > lv, V[N], S[N];
set < pair < int , int > > Q;
int main()
{
    scanf("%d", &n); m = n;
    for (int i = 1; i < n; i++)
        scanf("%d%d", &r, &t), V[r].insert(t), V[t].insert(r);
    for (int i = 1;  i <= n; i++)
        if (V[i].size() == 1)
            lv.insert(i);
    for (auto X : lv)
    {
        A[X] = 1;
        int id = *V[X].begin(), pr = X;
        while (V[id].size() == 2)
        {
            auto it = V[id].begin(); it ++;
            int pp = pr; pr = id;
            id = *V[id].begin() + *it - pp, A[X] ++;

        }
        P[X] = id; T[X] = pr;
        S[P[X]].insert(X);
        Q.insert({A[X], X});
    }
    for (int i = lv.size(); i <= n; i++)
        R[i] = n;
    R[1] = 1;
    while (Q.size() > 2)
    {
        auto X = *Q.begin(); Q.erase(Q.begin());
        m -= X.x; R[Q.size()] = m;
        S[P[X.y]].erase(X.y);
        V[P[X.y]].erase(T[X.y]);
        if (Q.size() == 2)
            break;
        if (S[P[X.y]].size() > 1 || S[P[X.y]].size() == 0)
            continue;
        int v = *S[P[X.y]].begin(), pr = T[v], id = P[v], av = A[v];
        while (V[id].size() == 2)
        {
            auto it = V[id].begin(); it ++;
            int pp = pr; pr = id;
            id = *V[id].begin() + *it - pp, A[v] ++;
        }
        P[v] = id; T[v] = pr;
        S[P[v]].insert(v);
        Q.erase({av, v});
        Q.insert({A[v], v});
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", R[i]);
    return (0);
}