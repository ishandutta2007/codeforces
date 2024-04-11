#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:167772016")

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

typedef long long li;
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9) + 6;
const li INF64 = li(1e18);
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

int n;
const int N = 1000;
string s[N];

bool read() 
{   
    cin >> n;
    forn (i, n)
        cin >> s[i];
    return true;
}

vector<int> g[50];

vector<int> x;
bool used[50];

void dfs(int v)
{
    if (used[v])
        return;
    used[v] = true;
    forn (i, g[v].size())
        dfs(g[v][i]);
    x.pb(v);
}

void solve() 
{   
    forn (i, n - 1)
    {
        forn (j, min(s[i].size(), s[i + 1].size()))
            if (s[i][j] != s[i + 1][j])
            {
                g[s[i + 1][j] - 'a'].pb(s[i][j] - 'a');
                break;
            }
    }

    forn (i, 26)
        dfs(i);

    int pos[26];
    forn (i, 26)
        pos[x[i]] = i;

    forn (i, n)
        forn (j, s[i].size())
            s[i][j] = pos[s[i][j] - 'a'] + 'a';

    forn (i, n - 1)
    {
        if (s[i] > s[i + 1])
        {
            cout << "Impossible" << endl;
            return;
        }
    }

    forn (i, 26)
        cout << char(x[i] + 'a');
    cout << endl;
}

int main() 
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    read();
    solve();

    return 0;
}