#include <cassert>
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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5;

ll sum = 0;
ll curt = 0;
queue<int> q;
int n, b; 

void popUntil(int t) {
    while (!q.empty() && curt + q.front() <= t) {
        curt += q.front();
        sum -= q.front();
        q.pop();
    }
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    scanf("%d%d", &n, &b);
    b++;
    forn(i, n) {
        int t, d;
        scanf("%d%d", &t, &d);
        popUntil(t);
        if (q.size() >= b) {
            cout << -1 << ' ';
        } else {
            if(q.size() == 0) {
                curt = t;
            }
            q.push(d);
            sum += d;
            cout << curt + sum << ' ';
        }
    }
    cout << '\n';
    return 0;
}