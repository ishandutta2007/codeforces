#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 3100;
const ll P = 998244353;
const ll MOD = 750317;

int N;
string s[MAXN], e[MAXN];
bool eq[MAXN];
int lo[MAXN], hi[MAXN];
string goal, maker;

ll cpow[MAXN];

int figure (string X, string M)
{
    if (M.length() > X.length())
        return -1;

    int x = X.length(), m = M.length();
    ll cm = 0, cgoal = 0;
    for (int i = 0; i < m; i++)
    {
        cm = (cm * MOD + X[i]) % P;
        cgoal = (cgoal * MOD + M[i]) % P;
    }

    for (int i = 0; i <= x - m; i++)
    {
        if (cm == cgoal)
        {
            bool bad = false;
            for (int j = 0; j < M.length(); j++)
                if (X[i+j] != M[j])
                {
                    bad = true;
                    break;
                }
            if (!bad) return i;            
        }
        if (i < x - m)
        {
            cm = (cm - cpow[m-1] * X[i]) % P + P;
            cm = (cm * MOD + X[i+m]) % P;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cpow[0] = 1;
    for (int i = 1; i < MAXN; i++)
        cpow[i] = (cpow[i-1] * MOD) % P;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> s[i];
    for (int i = 0; i < N; i++)
        cin >> e[i];

    int clen = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == e[i])
        {
            eq[i] = true;
            continue;
        }
        eq[i] = false;

        for (int j = 0; j < s[i].length(); j++)
            if (s[i][j] != e[i][j])
                hi[i] = j;
        for (int j = s[i].length() - 1; j >= 0; j--)
            if (s[i][j] != e[i][j])
                lo[i] = j;
        clen = hi[i] - lo[i] + 1;
    }

    bool bad = false;
    for (int i = 0; i < N; i++)
        if (!eq[i] && (hi[i] - lo[i] + 1 != clen))
        {
            bad = true;
        }

    if (!bad)
    {
        for (int i = 0; i < clen; i++)
        {
            char c = '.';
            for (int j = 0; j < N; j++)
            {
                if (eq[j]) continue;
                if (c == '.')
                    c = s[j][i+lo[j]];
                else if (c != s[j][i+lo[j]])
                    bad = true;
            }
        }
        for (int i = 0; i < clen; i++)
        {
            char c = '.';
            for (int j = 0; j < N; j++)
            {
                if (eq[j]) continue;
                if (c == '.')
                    c = e[j][i+lo[j]];
                else if (c != e[j][i+lo[j]])
                    bad = true;
            }
        }
    }

    if (bad)
    {
        cout << "NO\n";
        return 0;
    }

    while (true)
    {
        bool done = false;
        for (int i = 0; i < N; i++)
            if (!eq[i] && (lo[i] == 0))
                done = true;
        if (done) break;

        char c = '.';
        for (int i = 0; i < N; i++)
        {
            if (!eq[i])
            {
                if (c == '.')
                    c = s[i][lo[i]-1];
                else if (c != s[i][lo[i]-1])
                    done = true;
            }
        }
        if (done) break;
        for (int i = 0; i < N; i++)
            if (!eq[i])
                lo[i]--;
    }

    while (true)
    {
        bool done = false;
        for (int i = 0; i < N; i++)
            if (!eq[i] && (hi[i] + 1 == s[i].length()))
                done = true;
        if (done) break;

        char c = '.';
        for (int i = 0; i < N; i++)
        {
            if (!eq[i])
            {
                if (c == '.')
                    c = s[i][hi[i]+1];
                else if (c != s[i][hi[i]+1])
                    done = true;
            }
        }
        if (done) break;
        for (int i = 0; i < N; i++)
            if (!eq[i])
                hi[i]++;
    }

    goal = "";
    maker = "";
    for (int i = 0; i < N; i++)
    {
        if (eq[i]) continue;
        for (int j = lo[i]; j <= hi[i]; j++)
        {
            goal += s[i][j];
            maker += e[i][j];
        }
        break;
    }

    for (int i = 0; i < N; i++)
    {
        if (eq[i])
        {
            if (figure (s[i], goal) != -1)
                bad = true;
        }
        if (!eq[i])
        {
            if (figure (s[i], goal) != lo[i])
                bad = true;
        }
    }
    if (bad)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << goal << "\n" << maker << "\n";
}