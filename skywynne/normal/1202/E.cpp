// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 200005, SGM = 26;
int n, m, ts, M[N], Q[N], Suf[N], C[N][SGM], F[N], G[N];
string A, S[N];
inline void Add(string s)
{
    int id = 0;
    for (int i = 0; i < (int)s.size(); i ++)
    {
        if (!C[id][s[i] - 'a'])
            C[id][s[i] - 'a'] = ++ ts;
        id = C[id][s[i] - 'a'];
    }
    M[id] ++;
}
inline void AhoCorasick()
{
    int l = 0, r = 0;
    for (int i = 0; i < SGM; i ++)
        if (C[0][i])
            Q[r ++] = C[0][i];
    while (r - l)
    {
        int id = Q[l ++];
        for (int i = 0; i < SGM; i ++)
        {
            if (!C[id][i])
                C[id][i] = C[Suf[id]][i];
            else
                Suf[C[id][i]] = C[Suf[id]][i], Q[r ++] = C[id][i];
        }
        M[id] += M[Suf[id]];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> A >> n;
    for (int i = 1; i <= n; i ++)
        cin >> S[i], Add(S[i]);
    AhoCorasick();
    int id = 0;
    for (int i = 0; i < (int)A.size(); i ++)
        id = C[id][A[i] - 'a'], F[i] += M[id];
    ts = 0;
    memset(M, 0, sizeof(M));
    memset(C, 0, sizeof(C));
    memset(Suf, 0, sizeof(Suf));
    for (int i = 1; i <= n; i ++)
        reverse(S[i].begin(), S[i].end()), Add(S[i]);
    AhoCorasick();
    id = 0;
    for (int i = (int)A.size() - 1; ~ i; i --)
        id = C[id][A[i] - 'a'], G[i] += M[id];
    long long tot = 0;
    for (int i = 0; i < (int)A.size(); i ++)
        tot += 1LL * F[i] * G[i + 1];
    return !printf("%lld\n", tot);
}