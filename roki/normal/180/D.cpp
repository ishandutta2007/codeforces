#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

typedef pair<ld, ld> pt;
#define ft first
#define sc second
#define x first
#define y second

string s, t;


bool read() {
    return cin >> s >> t;
}

string ans;
int cnt[26];
bool any = false;

bool restore(int pos) {
    if (pos == s.size())
        return any;
    forn (i, 26) {
        if (!cnt[i])
            continue;
        cnt[i]--;
        if (!any && i >= t[pos] - 'a') {
            if (i > t[pos] - 'a')
                any = true;
            if (restore(pos + 1)) {
                ans += char('a' + i);
                return true;
            }
        }
        if (any && restore(pos + 1)) {
            ans += char('a' + i);
            return true;
        }
        cnt[i]++;
    }
    return false;
}

void solve() {
    while(t.size() < s.size())
        t += char('a' - 1);
    forn (i, s.size())
        cnt[s[i] - 'a']++;
    if (!restore(0))
        cout << -1 << endl;
    else {
        reverse(all(ans));
        cout << ans << endl;
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    while (read())
        solve();
    
    return 0;
}