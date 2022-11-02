// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;
struct Data {int a, b, c, d, id, val;};
int n, m, q;
Data D[N], F[N];
vector < int > ST[N], EN[N];
bool CMP1(Data a, Data b)
{
    return (a.b < b.b);
}
bool CMP2(Data a, Data b)
{
    return (a.a < b.a);
}
inline bool Solve()
{
    vector < int > U;
    sort(D + 1, D + n + 1, CMP1);
    for (int i = 1; i <= n; i ++)
        D[i].id = i;
    for (int i = 1; i <= n; i ++)
        F[i] = D[i];
    int r = 1;
    sort(F + 1, F + n + 1, CMP2);
    for (int i = 1; i <= n; i ++)
    {
        while (r <= n && D[r].b < F[i].a)
            r ++;
        F[i].val = r - 1;
        U.push_back(F[i].c);
        U.push_back(F[i].d + 1);
    }
    sort(U.begin(), U.end());
    for (int i = 1; i <= n; i ++)
    {
        F[i].c = (int)(lower_bound(U.begin(), U.end(), F[i].c) - U.begin());
        F[i].d = (int)(lower_bound(U.begin(), U.end(), F[i].d + 1) - U.begin());
        ST[F[i].c].push_back(i);
        EN[F[i].d].push_back(i);
    }
    bool fail = 0;
    set < int > sett;
    for (int i = 0; i < (int)U.size(); i ++)
    {
        for (int id : EN[i])
            if (*sett.begin() <= F[id].val)
                fail = 1;
        for (int id : EN[i])
            sett.erase(F[id].id);
        for (int id : ST[i])
            sett.insert(F[id].id);
        for (int id : ST[i])
            if (*sett.begin() <= F[id].val)
                fail = 1;
    }
    for (int i = 0; i <= (int)U.size() + 5; i ++)
        ST[i].clear(), EN[i].clear();
    return (fail);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d%d%d%d", &D[i].a, &D[i].b, &D[i].c, &D[i].d);
    bool w1 = Solve();
    for (int i = 1; i <= n; i ++)
        D[i].b *= -1, D[i].a *= -1, swap(D[i].a, D[i].b);
    w1 |= Solve();
    for (int i = 1; i <= n; i ++)
        D[i].b *= -1, D[i].a *= -1, swap(D[i].a, D[i].b);
    for (int i = 1; i <= n; i ++)
        swap(D[i].a, D[i].c), swap(D[i].b, D[i].d);
    w1 |= Solve();
    for (int i = 1; i <= n; i ++)
        D[i].b *= -1, D[i].a *= -1, swap(D[i].a, D[i].b);
    w1 |= Solve();
    if (w1)
        return !printf("NO\n");
    printf("YES\n");
    return 0;
}