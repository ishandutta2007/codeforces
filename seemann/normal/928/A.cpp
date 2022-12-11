#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

void normalize(char& c) {
    if (islower(c)) {
        c = toupper(c);
    }

    if (c == 'O') {
        c = '0';
    }

    if (c == 'L' || c == 'I') {
        c = '1';
    }
}

void normalize(string& s) {
    for (int i = 0; i < s.length(); ++i) {
        normalize(s[i]);
    }
}

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif

    string query;
    cin >> query;
    normalize(query);
    set<string> used;
    int n;
    cin >> n;
    forn(i, n) {
        string s;
        cin >> s;
        normalize(s);
        used.insert(s);
    }

    if (used.count(query)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    
    return 0;
}