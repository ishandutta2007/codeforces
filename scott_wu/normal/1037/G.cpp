#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const int A = 26;

int N, Q;
string S;
int cnext[MAXN][A], cprev[MAXN][A], pref[MAXN][A], suff[MAXN][A];
int pxor[MAXN];

int ssolve (int l, int r)
{
    if (l > r) return 0;
    int mask = 0;
    for (int i = 0; i < A; i++)
    {
        int cfirst = cnext[l][i], clast = cprev[r][i];
        if (cfirst > r) continue;

        if (pref[l][i] == -1) pref[l][i] = ssolve (l, cfirst - 1);
        if (suff[r][i] == -1) suff[r][i] = ssolve (clast + 1, r);
        int res = pxor[cfirst] ^ pxor[clast] ^ pref[l][i] ^ suff[r][i];
        mask |= (1 << res);
    }
    int ans = 0;
    while (mask & (1 << ans))
        ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> S;
    N = S.length();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < A; j++)
            pref[i][j] = suff[i][j] = -1;
    for (int i = 0; i < A; i++)
    {
        cnext[N-1][i] = N;
        cprev[0][i] = -1;
    }
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            for (int j = 0; j < A; j++)
                cprev[i][j] = cprev[i-1][j];
        cprev[i][S[i]-'a'] = i;
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (i < N - 1)
            for (int j = 0; j < A; j++)
                cnext[i][j] = cnext[i+1][j];
        cnext[i][S[i]-'a'] = i;
    }

    for (int i = 1; i < N; i++)
    {
        int ploc = cprev[i-1][S[i] - 'a'];
        if (ploc >= 0)
            pxor[i] = pxor[ploc] ^ ssolve (ploc + 1, i - 1);
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (ssolve (l, r))
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}