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
const int INF = 1e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

vector<int> delta;

void modif(int ci, int del, int l, int r, int cl, int cr) {
    l = max(l, cl);
    r = min(r, cr);
    if (l == cl && r == cr) {
        delta[ci] += del;
        return;
    }
    if (l >= r) {
        return;
    }
    int mid = (cl + cr) / 2;
    modif(ci * 2 + 1, del, l, r, cl, mid);
    modif(ci * 2 + 2, del, l, r, mid, cr);
}

int getat(int ci, int ind, int cl, int cr) {
    if (cr - cl == 1) {
        return delta[ci];
    }
    int mid = (cl + cr) / 2;
    if (ind < mid) {
        return delta[ci] + getat(ci * 2 + 1, ind, cl, mid);
    }
    return delta[ci] + getat(ci * 2 + 2, ind, mid, cr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    delta.assign(n * 4 + 5, 0);
    string s, rs;
    cin >> s;
    rs = s;
    reverse(rs.begin(), rs.end());

    vector<int> selem(n);
    vector<queue<int>> fir('z' - 'a' + 1);
    for (int i = 0; i < n; ++i) {
        fir[s[i] - 'a'].push(i);
    }
    for (int i = 0; i < n; ++i) {
        selem[i] = fir[rs[i] - 'a'].front();
        fir[rs[i] - 'a'].pop();
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += selem[i] + getat(0, selem[i], 0, n) - i;
        modif(0, 1, 0, selem[i], 0, n);
    }

    cout << ans << "\n";

    return 0;
}