#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int pmax = 1000 * 1001;
const int64 amax = 1ll * 1000000 * 1000000 + 1000;

bitset<pmax> used;
vector<int> pr;
vector<int64> good[100100];
vector<vector<int64> > e;

map<pair<int, int64>, int64 > h;

int check(int64 now) {
    now --;
    if (now < 1e6) return 0;
    forn(i, pr.size())
        if (now % pr[i] == 0) return 0;
    return 1;
}

int64 go(int idx, int64 now) {
    if (now == 1) {
        return 1;
    }

    if (idx > 0 && now % 2 == 1) return 0;
    if (h.count(mp(idx, now)))
        return h[mp(idx, now)];
    if (idx >= e.size()) return h[mp(idx, now)] = check(now);


    int64 res = 0;

    forn(i, e[idx].size())
        if (now % e[idx][i] == 0)
            res += go(idx + 1, now / e[idx][i]);
    res += go(idx + 1, now);

    return h[mp(idx, now)] = res;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    int64 a;
    cin >> a;
    used.reset();
    used[0] = used[1] = 1;
    for (int i = 2; i < pmax; i ++) 
        if (!used[i]) {
            pr.pb(i);
            for (int64 j = 1ll * i * i; j < pmax; j += i)
                used[j] = 1;
        }

    int now = 0;
    e.clear();
    forn(i, pr.size()) {
        vector<int64> buf;
        int64 k = pr[i];
        while (0 < k && k <= a) {
            if (a % (k + 1) == 0) {
                buf.pb(k + 1);
                now ++;
            }
            k *= pr[i];
        }
        if (buf.size() > 0)
            e.pb(buf);
    }
    int64 res = go(0, a);
    cout << res << endl;

    return 0;
}