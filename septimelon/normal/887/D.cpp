#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 2e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

vector<ll> minpref;

void modif(int ci, int cl, int cr, int ind, ll del) {
    if (cl == cr - 1) {
        minpref[ci] = del;
        return;
    }
    int mid = (cl + cr) / 2;
    if (mid > ind) {
        modif(ci * 2 + 1, cl, mid, ind, del);
    }
    else {
        modif(ci * 2 + 2, mid, cr, ind, del);
    }
    minpref[ci] = min(minpref[ci * 2 + 1], minpref[ci * 2 + 2]);
}

ll getat(int ci, int cl, int cr, int l, int r) {
    //cout << cl << "," << cr << "," << minpref[ci] << "|";
    l = max(l, cl);
    r = min(r, cr);
    if (l >= r) {
        if (ci == 0) {
            return 0LL;
        }
        return INFL;
    }
    if (l == cl && r == cr) {
        return minpref[ci];
    }
    int mid = (cl + cr) / 2;
    return min(getat(ci * 2 + 1, cl, mid, l, r), getat(ci * 2 + 2, mid, cr, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, a, b, c, d, start, len;
    cin >> n >> a >> b >> c >> d >> start >> len;
    vector<int> t(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> q[i];
    }

    t.push_back(INF);

    minpref.assign(n * 4 + 5, INFL);
    ll cpr = 0LL;
    for (int i = 0; i < n; ++i) {
        if (q[i] == 0) {
            cpr -= d;
        }
        else {
            cpr += c;
        }
        modif(0, 0, n, i, cpr);
    }

    int cl = 0, cr = 0;
    ll lastt = -1;
    ll cs = start;
    while (cs >= 0 && cl < n) {
        while (t[cr] < lastt + len) {
            ++cr;
        }
        if (t[cr] > lastt + len) {
            //cout << cl << ", " << cr << ": " << cs << " " << getat(0, 0, n, cl, cr) << " " << getat(0, 0, n, cl - 1, cl) << "\n";
            if (cs + getat(0, 0, n, cl, cr) - getat(0, 0, n, cl - 1, cl) >= 0) {
                cout << lastt + 1 << "\n";
                return 0;
            }
        }
        while (t[cr] < t[cl] + len) {
            ++cr;
            //cout << cl << ", " << cr << ": " << cs << " " << getat(0, 0, n, cl, cr) << " " << getat(0, 0, n, cl - 1, cl) << "\n";
            if (cs + getat(0, 0, n, cl, cr) - getat(0, 0, n, cl - 1, cl) >= 0) {
                cout << max(lastt + 1, t[cr - 1] - len + 1) << "\n";
                return 0;
            }
        }
        if (q[cl] == 0) {
            cs -= b;
        }
        else {
            cs += a;
        }
        lastt = t[cl];
        ++cl;
    }
    if (cs >= 0) {
        cout << t[n - 1] + 1 << "\n";
        return 0;
    }

    cout << "-1\n";

    return 0;
}