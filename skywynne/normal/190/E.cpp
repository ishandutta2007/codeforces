#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 5e5 + 10;
int n, m, r, t, ts;
set < pair < int , int > > S, T;
vector < int > V[N], res[N];
bool Check(int v, int p)
{
    int le = 0, ri = (int)V[v].size(), mid;
    if (ri == 0)
        return (0);
    while (ri - le > 1)
    {
        mid = (le + ri) / 2;
        if (V[v][mid] <= p)
            le = mid;
        else
            ri = mid;
    }
    return (V[v][le] == p);
}
void Discover(int v)
{
    auto it = S.begin();
    while (it != S.end())
    {
        auto last = *it;
        if (!Check(v, last.y))
        {
            T.insert(last);
            S.erase(it);
        }
        it = S.upper_bound(last);
    }
}
void Solve()
{
    while (T.size() > 0)
    {
        int v = (*T.begin()).y;
        T.erase(T.begin());
        Discover(v);
        res[ts].push_back(v);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &r, &t);
        V[r].push_back(t);
        V[t].push_back(r);
    }
    for (int i = 1; i <= n; i++)
        sort(V[i].begin(), V[i].end());
    for (int i = 1; i <= n; i++)
        S.insert({(int)V[i].size(), i});
    while (S.size() > 0)
    {
        auto X = *S.begin();
        S.erase(S.begin());
        T.insert(X);
        Solve(); ts ++;
    }
    printf("%d", ts);
    for (int i = 0; i < ts; i++)
    {
        printf("\n%d ", (int)res[i].size());
        for (auto X : res[i])
            printf("%d ", X);
    }
    return (0);
}