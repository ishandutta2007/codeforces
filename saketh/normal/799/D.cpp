#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int need(ll A, ll H) {
    int ct = 0;
    while (H < A) {
        H *= 2;
        ct++;
    }
    return ct;
}

int solve(ll A, ll B, ll H, ll W, vll &ext, int twos) {
    if (A <= H && B <= W) {
        return 0;
    }

    vll cand;
    ll HH = H, WW = W;

    for (ll v : ext) {
        if (v == 2) break;
        if (HH < A) { 
            HH *= v;
            cand.push_back(v);
        } else if (WW < B) {
            WW *= v;
            cand.push_back(v);
        } else break;
    }

    int ret = INT_MAX;

    int only_twos = need(A, H) + need(B, W);
    if (only_twos <= twos)
        ret = only_twos;

    int needA = 0, needB = 0;
    ll multA = 1, multB = 1;

    for (int m = 0; m < (1 << cand.size()); m++) {
        ll HH = H, WW = W;
        for (int i = 0; i < cand.size(); i++) {
            if ((m >> i) & 1) {
                HH = min(A, HH * cand[i]);
            } else {
                WW = min(B, WW * cand[i]);
            }

            while (HH * multA < A) {
                multA *= 2;
                needA++;
            }

            while (WW * multB < B) {
                multB *= 2;
                needB++;
            }

            while (multA > 1 && HH * multA/2 >= A) {
                multA /= 2;
                needA--;
            }

            while (multB > 1 && WW * multB/2 >= B) {
                multB /= 2;
                needB--;
            }

            if (needA + needB <= twos) {
                ret = min(ret, i + 1 + needA + needB);
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll A, B, H, W;
    cin >> A >> B >> H >> W;

    int N;
    cin >> N;

    vll ext(N);
    for (int i = 0; i < N; i++) {
        cin >> ext[i];
    }

    sort(all(ext));

    int twos = 0;
    for (ll v : ext)
        if (v == 2)
            twos++;

    reverse(all(ext));

    int ans = INT_MAX;
    ans = min(ans, solve(A, B, H, W, ext, twos));
    ans = min(ans, solve(B, A, H, W, ext, twos));
    cout << (ans == INT_MAX ? -1 : ans) << endl;

    return 0;
}