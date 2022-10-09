#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

ll len(ll n) {
    if (n <= 1) {
        return 1;
    }
    return len(n / 2) * 2 + 1;
}

ll ones(ll n) {
    if (n <= 1) {
        return n;
    }
    return ones(n / 2) * 2 + n % 2;
}

ll rec(ll n, ll l, ll r, ll L = 0) {
    if (r <= l) {
        return 0;
    }
    if (L >= r) {
        return 0;
    }
    ll R = L + len(n);
    if (R <= l) {
        return 0;
    }
    if (l <= L && R <= r) {
        return ones(n);
    }
    ll d = len(n / 2);
    return rec(n / 2, l, r, L) + rec(n % 2, l, r, L + d) + rec(n / 2, l, r, L + d + 1);
}

int main() {
    ios::sync_with_stdio(false);
    ll n, l, r;
    cin >> n >> l >> r;
    --l;
    cout << rec(n, l, r) << endl;
    return 0;
}