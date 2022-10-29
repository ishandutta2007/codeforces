#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<ld, ld> pt;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ft first
#define sc second
#define x first
#define y second

const int INF = 1e9;
const ld EPS = 1e-10;

string s;
string t = "xyz";

bool read()
{
    return (cin >> s);
    return true;
}

int cnt[3][100005];

void solve() 
{
    int m;
    cin >> m;
    
    forn (i, 3)
        forn (j, s.size())
            cnt[i][j + 1] = cnt[i][j] + (s[j] == t[i]);

    forn (i, m)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (r - l < 2)
        {
            cout << "YES" << endl;
            continue;
        }
        int x = cnt[0][r + 1] - cnt[0][l];
        int y = cnt[1][r + 1] - cnt[1][l];
        int z = cnt[2][r + 1] - cnt[2][l];
        if (abs(x - y) > 1 || abs(y - z) > 1 || abs(x - z) > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}   

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    while(read())
        solve();

    return 0;
}