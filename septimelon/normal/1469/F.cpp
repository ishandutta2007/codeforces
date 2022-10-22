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
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

vector<ll> sumo;
vector<ll> prot;

void upd(int ci, int cl, int cr) {
    sumo[ci] += prot[ci] * (ll)(cr - cl);
    if (cr - cl > 1) {
        prot[ci * 2 + 1] += prot[ci];
        prot[ci * 2 + 2] += prot[ci];
    }
    prot[ci] = 0;
}

void modif(int ci, int cl, int cr, int l, int r, ll del) {
    l = max(l, cl);
    r = min(r, cr);
    if (l >= r) {
        return;
    }
    if (l <= cl && r >= cr) {
        prot[ci] += del;
        return;
    }
    sumo[ci] += del * (ll)(r - l);
    int mid = (cl + cr) / 2;
    modif(ci * 2 + 1, cl, mid, l, r, del);
    modif(ci * 2 + 2, mid, cr, l, r, del);
}

int getlp(int ci, int cl, int cr) {
    upd(ci, cl, cr);
    //cout << cl << " - " << cr << ": " << sumo[ci] << "\n";
    if (sumo[ci] == 0) {
        return -1;
    }
    if (cr - cl == 1) {
        return cl;
    }
    int ans = getlp(ci * 2 + 1, cl, (cl + cr) / 2);
    if (ans == -1) {
        ans = getlp(ci * 2 + 2, (cl + cr) / 2, cr);
    }
    return ans;
}

int getkth(int ci, int cl, int cr, int& k) {
    upd(ci, cl, cr);
    if (sumo[ci] < k) {
        k -= sumo[ci];
        return -1;
    }
    if (cr - cl == 1) {
        return cl;
    }
    int quel = getkth(ci * 2 + 1, cl, (cl + cr) / 2, k);
    if (quel == -1) {
        quel = getkth(ci * 2 + 2, (cl + cr) / 2, cr, k);
    }
    return quel;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int righ = 1000000;
    sumo.assign(righ * 4 + 5, 0);
    prot.assign(righ * 4 + 5, 0);
    modif(0, 0, righ, 0, 1, 1);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int mind = 1e9;
    for (int i = 0; i < n; ++i) {
        int lef = getlp(0, 0, righ);
        if (lef == -1) {
            cout << "wtf\n";
            break;
        }
        int len1 = (a[i] - 1) / 2, len2 = a[i] / 2;
        modif(0, 0, righ, lef, lef + 1, -1);
        modif(0, 0, righ, lef + 2, lef + 2 + len1, 1);
        modif(0, 0, righ, lef + 2, lef + 2 + len2, 1);
        int ck = k;
        int kth = getkth(0, 0, righ, ck);
        if (kth > 0) {
            mind = min(mind, kth);
        }
    }

    if (mind > righ) {
        cout << "-1\n";
    }
    else {
        cout << mind << "\n";
    }
}