#include<bits/stdc++.h>
using namespace std;
const int N = 1000007, SGM = 26;
int n, q, k, ts = 1, C[N][SGM], Suf[N], Ac[N], Qu[N], R[N], F[N], st[N], en[N], Mark[N];
vector < int > Adj[N];
char S[N];
inline int Add(char * _S)
{
    int i = 0, id = 0;
    while (_S[i])
    {
        if (!C[id][_S[i] - 'a'])
            C[id][_S[i] - 'a'] = ++ n;
        id = C[id][_S[i] - 'a']; i++;
    }
    Ac[id] = 1;
    return (id);
}
inline void AhoCorasick()
{
    int l = 0, r = 0, id;
    for (int i = 0; i < SGM; i++)
        if (C[0][i])
            Qu[r ++] = C[0][i];
    while (r - l)
    {
        id = Qu[l ++];
        for (int i = 0; i < SGM; i++)
        {
            if (!C[id][i])
                C[id][i] = C[Suf[id]][i];
            else
                Qu[r ++] = C[id][i], Suf[C[id][i]] = C[Suf[id]][i];
        }
        if (Suf[id] && !Ac[Suf[id]])
            Suf[id] = Suf[Suf[id]];
        Adj[Suf[id]].push_back(id);
    }
}
void DFS(int v, int p = -1)
{
    st[v] = ts ++;
    for (int &u : Adj[v])
        if (u != p)
            DFS(u, v);
    en[v] = ts;
}
inline void Add(int i, int val)
{
    for (; i < N; i += i & -i)
        F[i] += val;
}
inline int Get(int i)
{
    int ret = 0;
    for (; i; i -= i & -i)
        ret += F[i];
    return (ret);
}
inline int Run(char * _S)
{
    int i = 0, id = 0, ret = 0;
    while (_S[i])
        id = C[id][_S[i ++] - 'a'], ret += Get(st[id]);
    return (ret);
}
int main()
{
    scanf("%d%d", &q, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%s", &S);
        R[i] = Add(S);
        fill(S, S + strlen(S), 0);
    }
    AhoCorasick(); DFS(0);
    for (int i = 1; i <= k; i++)
        Add(st[R[i]], 1), Add(en[R[i]], -1), Mark[i] = 1;
    for (; q; q --)
    {
        int id;
        char ch;
        cin >> ch;
        if (ch == '?')
        {
            scanf("%s", &S);
            printf("%d\n", Run(S));
            fill(S, S + strlen(S), 0);
            continue;
        }
        scanf("%d", &id);
        if (ch == '+' && !Mark[id])
            Add(st[R[id]], 1), Add(en[R[id]], -1), Mark[id] = 1;
        if (ch == '-' && Mark[id])
            Add(st[R[id]], -1), Add(en[R[id]], 1), Mark[id] = 0;
    }
    return (0);
}