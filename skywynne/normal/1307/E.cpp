// Skywynne
#include<bits/stdc++.h>
using namespace std;
const int N = 5005, Mod = 1e9 + 7;
int n, m, q, A[N], L[N], R[N], C[N][N];
vector < int > F[N], V[N];
pair < int , int > B[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> A[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            C[i][j] = C[i][j - 1] + (A[j] == i);
    for (int i = 1; i <= m; i ++)
    {
        int f, h;
        cin >> f >> h;
        F[f].push_back(h);
    }
    m = 0;
    for (int i = 1; i <= n; i ++)
    {
        sort(F[i].begin(), F[i].end());
        for (int h : F[i])
            B[++ m] = {i, h}, V[i].push_back(m);
    }
    for (int i = 1; i <= m; i ++)
    {
        int c = 0;
        L[i] = n + 1;
        for (int j = 1; j <= n; j ++)
        {
            if (A[j] == B[i].first)
                c ++;
            if (c == B[i].second)
                {L[i] = j; break;}
        }
        c = 0;
        R[i] = 0;
        for (int j = n; j; j --)
        {
            if (A[j] == B[i].first)
                c ++;
            if (c == B[i].second)
                {R[i] = j; break;}
        }
    }
    int Mx = 0, tot = 1;
    for (int i = 1; i <= n; i ++)
    {
        int id = -1;
        for (int j = 1; j <= m; j ++)
            if (L[j] == i)
                id = j;
        if (id == -1)
            continue;
        int cnt = 1, cc = 1;
        int color = B[id].first;
        if (V[color].size() > 1)
        {
            int hcc = C[color][n] - C[color][i];
            int lb = upper_bound(F[color].begin(), F[color].end(), hcc) - F[color].begin();
            if (B[id].second <= hcc)
                lb --;
            if (lb)
            {
                cnt ++;
                cc = 1LL * cc * lb % Mod;
            }
        }
        for (int j = 1; j <= n; j ++)
            if (V[j].size() && j != B[id].first)
            {
                int aa = C[j][i - 1];
                int bb = C[j][n] - C[j][i];

                if (aa > bb)
                    swap(aa, bb);

                int laa = upper_bound(F[j].begin(), F[j].end(), aa) - F[j].begin();
                int lbb = upper_bound(F[j].begin(), F[j].end(), bb) - F[j].begin();

                if (laa > 0 && lbb > 1)
                {
                    cnt += 2;
                    cc = 1LL * cc * laa * (lbb - 1) % Mod;
                    continue;
                }
                if (laa && lbb)
                {
                    cnt += 1;
                    cc = 1LL * cc * 2 % Mod;
                    continue;
                }
                if (lbb)
                {
                    cnt += 1;
                    cc = 1LL * cc * lbb % Mod;
                    continue;
                }
            }
        if (Mx < cnt)
            Mx = cnt, tot = 0;
        if (Mx == cnt)
            tot = (tot + cc) % Mod;
    }
    int cnt = 0, cc = 1;
    for (int i = 1; i <= n; i ++)
        if (V[i].size())
        {
            int ff = 0;
            for (int j : V[i])
                if (R[j] > 0)
                    ff ++;
            if (ff)
                cnt ++, cc = 1LL * cc * ff % Mod;
        }
    if (Mx < cnt)
        Mx = cnt, cc = 0;
    if (Mx == cnt)
        tot = (tot + cc) % Mod;
    if (Mx == 0)
        tot = 1;
    printf("%d %d\n", Mx, tot);
    return 0;
}