// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, A[N], V[N], U[N], D[N];
long long F[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        scanf("%d%d%d", &U[i], &V[i], &D[i]);
        F[U[i]] += D[i];
        F[V[i]] -= D[i];
    }
    set < pair < long long , int > > PS, NG;
    for (int i = 1; i <= n; i ++)
    {
        if (F[i] > 0)
            PS.insert({F[i], i});
        if (F[i] < 0)
            NG.insert({F[i], i});
    }
    vector < tuple < int , int , long long > > vec;
    while (PS.size())
    {
        if (PS.begin()->first <= - NG.rbegin()->first)
        {
            int pid = PS.begin()->second;
            PS.erase(PS.begin());
            int nid = NG.rbegin()->second;
            NG.erase(*NG.rbegin());
            vec.push_back(make_tuple(pid, nid, F[pid]));
            F[nid] += F[pid]; F[pid] = 0;
            if (F[nid] < 0)
                NG.insert({F[nid], nid});
        }
        else
        {
            int pid = PS.begin()->second;
            PS.erase(PS.begin());
            int nid = NG.rbegin()->second;
            NG.erase(*NG.rbegin());
            vec.push_back(make_tuple(pid, nid, - F[nid]));
            F[pid] += F[nid]; F[nid] = 0;
            if (F[pid] > 0)
                PS.insert({F[pid], pid});
        }

    }
    printf("%d\n", (int)vec.size());
    for (auto X : vec)
    {
        int u, v;
        long long d;
        tie(u, v, d) = X;
        printf("%d %d %lld\n", u, v, d);
    }
    return 0;
}