#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXS = 110;
const int MAXN = 200100;

int N, Q;
string S, T;
int ssize;

bool good[MAXS];
ll p2[MAXN];
ll ps[MAXN][26];

ll figure (int ind, int cstep, vector <int> cv)
{
    if (cstep >= ind) return 0;

    if (cv.size() == 1)
    {
        int val = cv[0];
        ll res = ps[ind][val] - p2[ind-cstep] * ps[cstep][val];
        return (res % MOD + MOD) % MOD;
    }

    vector <int> left, right;
    for (int j = 0; j < cv.size(); j++)
    {
        if (j % 2 == 0)
            left.push_back (cv[j]);
        else
            right.push_back (cv[j]);
    }

    ll ans = 0;

    bool lgood = true;
    int nn = T[cstep] - 'a';
    for (int x : left)
        if (x != nn)
            lgood = false;
    if (lgood)
    {
        ans = (ans + figure (ind, cstep + 1, right)) % MOD;
    }
    lgood = true;
    for (int x : right)
        if (x != nn)
            lgood = false;
    if (lgood)
    {
        ans = (ans + figure (ind, cstep + 1, left)) % MOD;
    }
    return ans;
}

ll gogo (int ind, string P)
{
    for (int i = 0; i < MAXS; i++)
        good[i] = true;

    ll ans = 0;
    if (P.length() <= ssize)
    {
        for (int i = 0; i <= ssize; i++)
        {
            bool bad = false;
            int v = -1;
            int cv = i;
            for (int j = 0; j < P.length(); j++)
            {
                if (cv == ssize)
                    v = (P[j] - 'a');
                else if (S[cv] != P[j])
                {
                    bad = true;
                    break;
                }
                cv++;
                if (cv == ssize + 1)
                    cv = 0;
            }

            if (!bad)
            {
                if (v == -1)
                {
                    ans = (ans + p2[ind]) % MOD;
                }
                else
                {
                    vector <int> cc;
                    cc.push_back(v);
                    ans = ans + figure (ind, 0, cc);
                    ans %= MOD;
                }
            }
        }
        return ans;
    }

    for (int i = ssize + 1; i < P.length(); i++)
        if (P[i] != P[i % (ssize + 1)])
            good[i % (ssize + 1)] = false;

    for (int i = 0; i <= ssize; i++)
    {
        bool bad = false;
        int cv = i;
        for (int j = 0; j <= ssize; j++)
        {
            if (cv == ssize)
            {
                cv = 0;
                continue;
            }
            else if (!good[j] || S[cv] != P[j])
            {
                bad = true;
                break;
            }
            cv++;
        }

        if (!bad)
        {
            vector <int> v;
            for (int j = ssize - i; j < P.length(); j += (ssize + 1))
                v.push_back (P[j] - 'a');
            ans = (ans + figure (ind, 0, v)) % MOD;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);

    p2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        p2[i] = (2 * p2[i-1]) % MOD;


    cin >> N >> Q >> S >> T;
    ssize = S.length();

    for (int i = 0; i < 26; i++)
        ps[0][i] = 0;
    for (int j = 0; j < T.length(); j++)
    {
        int v = T[j] - 'a';
        for (int k = 0; k < 26; k++)
        {
            ps[j+1][k] = (2 * ps[j][k]) % MOD;
        }
        ps[j+1][v] = (ps[j+1][v] + 1) % MOD;
    }



    for (int i = 0; i < Q; i++)
    {
        int ind; string P;
        cin >> ind >> P;

        cout << gogo (ind, P) << "\n";
    }
}