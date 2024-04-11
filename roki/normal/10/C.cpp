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
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

const int N = 1000 * 1000 + 50;
int n;

bool read() {
    cin >> n;
    return true;
}

int f[N];

int calc(int x) {
    int res = 0;
    while(x) {
        res += x % 10;
        x /= 10;
    }
    return res < 10 ? res : calc(res);
}

void solve() {
    
    forn (i, N)
        f[i] = calc(i);

    li ans = 0;

    vector<int> cnt(10, 0);

    for (int i = 1; i <= n; ++i)
        cnt[f[i]]++;


    forn (i, 10) 
        forn (j, 10)
            forn (k, 10) {
                if (f[i * j] == f[k])
                    ans += li(cnt[i]) * cnt[j] * cnt[k];
            }
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; i * j <= n; ++j) {
            if (f[f[i] * f[j]] == f[i * j])
                ans--;
        }

    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    read();
    solve();

    return 0;
}