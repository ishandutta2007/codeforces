#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

string s;

inline bool read() {
    if (!(cin >> s))
        return false;
    return true;
}

int p[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool ok(string& s) 
{
    forn (i, s.size()) 
    {
        if (i == 2 || i == 5) 
        {
            if (s[i] != '-')
                return false;
        }
        else
            if (s[i] == '-')
                return false;
    }
    int d = 10 * (s[0] - '0') + s[1] - '0';
    int m = 10 * (s[3] - '0') + s[4] - '0';
    int y = 0;
    for (int j = s.size() - 4; j < s.size(); ++j)
    {
        y *= 10;
        y += s[j] - '0';
    }
    if (m == 0 || m > 12 || d == 0 || y < 2013 || y > 2015)
        return false;
    if (d > p[m - 1])
        return false;
    return true;
}

inline void solve() {
    map<string, int> m;
    string ans = "";
    m[""] = 0;
    forn (i, s.size() - 9)
    {
        string cur = s.substr(i, 10);
        if (ok(cur))
        {
            m[cur]++;
            if (m[ans] < m[cur])
                ans = cur;
        }
    }
    cout << ans << endl;
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}