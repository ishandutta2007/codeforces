#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 1000000007;

ll s[100100], a[100100], b[100100];
vector<pair<int, int> > A, B;
int n, S;
ll k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> S;
    ll sum = 0;
    ll sum_a = 0;
    ll sum_b = 0;
    forn (i, n) {
        cin >> s[i] >> a[i] >> b[i];
        sum += s[i];
        if (a[i] > b[i]) {
            sum_a += s[i];
            A.pb(mp(a[i] - b[i], i));
        } else {
            B.pb(mp(b[i] - a[i], i));
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sum_b = sum - sum_a;
    k = sum / S + bool(sum % S);
    ll k_a = sum_a / S + bool(sum_a % S);
    ll k_b = k - k_a;
    k_a *= S;
    k_b *= S;
    ll ans = 0;
    ll res = 0;
    forn (i, A.size()) {
        res += ll(a[A[i].sc]) * s[A[i].sc];
    }
    ll r = sum_b - k_b;
    forn (i, B.size()) {
        ll cur = 0;
        if (r > 0) {
            cur = min(r, s[B[i].sc]);
        }
        res += cur * a[B[i].sc];
        res += (s[B[i].sc] - cur) * b[B[i].sc];
        r -= cur;
    }
    ans = res;
    if (k_a) {
        k_a -= S;
        k_b += S;
        res = 0;
        forn (i, B.size()) {
            res += ll(b[B[i].sc]) * s[B[i].sc];
        }
        ll r = sum_a - k_a;
        forn (i, A.size()) {
            ll cur = 0;
            if (r > 0) {
                cur = min(r, s[A[i].sc]);
            }
            res += cur * b[A[i].sc];
            res += (s[A[i].sc] - cur) * a[A[i].sc];
            r -= cur;
        }
        ans = max(res, ans);
    }
    cout << ans << endl;
    return 0;
}