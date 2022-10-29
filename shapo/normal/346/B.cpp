#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define itr(x) x::iterator
#define X first
#define Y second

typedef pair < int, int > pii;
typedef pair < pii, int > piii;
typedef vector < int > vi;
typedef vector < vi > v2i;
typedef vector < v2i > v3i;

v3i ans;
string s1, s2, virus;
v2i goTo;
vector < vector < vector < piii > > > go;

bool
check(string &s, int p1, int p2)
{
    while (p2 >= 0)
    {
        if (s[p1] != s[p2])
        {
            return false;
        }
        --p1;
        --p2;
    }
    return true;
}

#ifdef _DEBUG
bool
#else
void
#endif
input_data(void)
{
#ifdef _DEBUG
    if (!(cin >> ws >> s1))
    {
        return false;
    }
#else
    cin >> skipws >> s1;
#endif
    cin >> skipws >> s2;
    cin >> skipws >> virus;
    ans.clear();
    goTo.assign(virus.size() + 1, vi(26, 0));
    for (int i = 0; i <= virus.size(); ++i)
    {
        for (int c = 0; c < 26; ++c)
        {
            char cur = c + 'A';
            int j = i;
            while (j >= 0)
            {
                if ((j != virus.size() && cur == virus[j]) && check(virus, i - 1, j - 1))
                {
                    break;
                }
                --j;
            }
            goTo[i][c] = j + 1;
#ifdef _NDEBUG
            cerr << "goTo[" << i << "][" << cur << "] = " << goTo[i][c] << endline;
#endif
        }
    }
#ifdef _DEBUG 
    return true;
#endif
}

string proc(int i, int j, int k)
{
#ifdef _DEBUG
    cerr << "proc " << i << " " << j << " " << k << endline;
#endif
    if (i == 0 || j == 0)
    {
        return string();
    }
    piii toGo = go[i][j][k];
    string res = proc(toGo.X.X, toGo.X.Y, toGo.Y);
    if (ans[i][j][k] == ans[toGo.X.X][toGo.X.Y][toGo.Y] + 1)
    {
        res += s1[i - 1];
    }
    return res;
}

void
calc(void)
{
    int l1 = s1.size();
    int l2 = s2.size();
    int lv = virus.size();
#ifdef _DEBUG
    cerr << l1 << " " << l2 << " " << lv << endline;
#endif
    ans.assign(l1 + 1, v2i(l2 + 1, vi(lv + 1, 0)));
    go.assign(l1 + 1, vector < vector < piii > >(l2 + 1, vector < piii >(lv + 1, mp(mp(-1, -1), -1))));
    for (int i = 0; i <= l1; ++i)
    {
        for (int j = 0; j <= l2; ++j)
        {
            for (int k = 0; k < lv; ++k)
            {
                if (i != l1)
                {
                    ans[i + 1][j][k] = max(ans[i + 1][j][k], ans[i][j][k]);
                    if (ans[i + 1][j][k] == ans[i][j][k])
                    {
                        go[i + 1][j][k] = mp(mp(i, j), k);
                    }
                }
                if (j != l2)
                {
                    ans[i][j + 1][k] = max(ans[i][j + 1][k], ans[i][j][k]);
                    if (ans[i][j + 1][k] == ans[i][j][k])
                    {
                        go[i][j + 1][k] = mp(mp(i, j), k);
                    }
                }
                if (i != l1 && j != l2 && s1[i] == s2[j])
                {
                    int nxt = goTo[k][s1[i] - 'A'];
                    ans[i + 1][j + 1][nxt] = max(ans[i + 1][j + 1][nxt], ans[i][j][k] + 1);
                    if (ans[i + 1][j + 1][nxt] == ans[i][j][k] + 1)
                    {
                        go[i + 1][j + 1][nxt] = mp(mp(i, j), k);
                    }
                }
            }
        }
    }
    int res = 0;
    int opt = -1;
    for (int i = 0; i < lv; ++i)
    {
        if (ans[l1][l2][i] > res)
        {
            res = ans[l1][l2][i];
            opt = i;
        }
    }
    if (opt == -1)
    {
        cout << "0" << endline;        
    }
    else
    {
        string res = proc(l1, l2, opt);
        cout << res << endline;
    }
}

int
main(void)
{
#ifndef _DEBUG
    ios_base::sync_with_stdio(false);
    input_data();
#else
    while (input_data()) {
#endif
    calc();
#ifdef _DEBUG
    }
#endif
    return 0;
}