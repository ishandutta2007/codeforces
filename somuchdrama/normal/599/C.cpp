#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 1;

pii arr[MAXN];
pii otr[MAXN + MAXN];

bool comp(const pii & a, const pii & b) {
    return a.ff < b.ff;
}

bool comp2(const pii & a, const pii & b) {
    if (a.ff == b.ff)
        return a.ss < b.ss;
    return a.ff > b.ff;
}

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].ff;
        arr[i].ss = i;
    }

    stable_sort(arr, arr + n, comp);

    for (int i = 0; i < n; ++i) {
        otr[i] = {min(arr[i].ss, i), 1};
        otr[i + n] =  {max(arr[i].ss, i), -1};
    }

    sort(otr, otr + n + n);

    int ans = 0;
    int deep = 0;
    for (int i = 0; i < n + n; ++i) {
        deep += otr[i].ss;
        if (deep == 0)
            ++ans;
    }

    cout << ans << '\n';

    return 0;
}