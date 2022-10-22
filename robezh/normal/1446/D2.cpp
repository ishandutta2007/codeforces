#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)4e5 + 50, INF = (int)1e9;

int n;
int a[N];
int freq[N];
int mxfreq = -1, mxi = 0;

int check(int x) {
    static int fir[2 * N];
    fill(fir, fir + 2 * n, -INF);
    fir[n] = -1;
    int curcnt = n, res = 0;
    rep(i, 0, n) {
        if(a[i] == mxi) curcnt++;
        else if(a[i] == x) curcnt--;
        if(fir[curcnt] == -INF) fir[curcnt] = i;
        else res = max(res, i - fir[curcnt]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i], a[i]--;
        freq[a[i]]++;
    }
    rep(i, 0, n) {
        if(freq[i] > mxfreq) {
            mxfreq = freq[i];
            mxi = i;
        }
    }
    rep(i, 0, n) {
        if(freq[i] == mxfreq && i != mxi) return cout << n << '\n', 0;
    }
    int B = 500;
    int res = 0;
    rep(i, 0, n) if(freq[i] >= B) res = max(res, check(i));


    fill(freq, freq + n, 0);
    vector<int> ocu;
    rep(i, 0, n) {
        if(a[i] == mxi) ocu.push_back(i);
        if(i == n - 1 || a[i + 1] == mxi) {
            int last = (sz(ocu) >= B ? ocu[sz(ocu) - B] : -1) + 1;
//            cout << last << " " << i << endl;
            int mxf = 0, mxcnt = 0;
            for(int j = i; j >= last; j--) {
                freq[a[j]]++;
                if(freq[a[j]] == mxf) {
                    mxcnt++;
                } else if(freq[a[j]] > mxf) {
                    mxf = freq[a[j]];
                    mxcnt = 1;
                }
                if(freq[mxi] == mxf && mxcnt >= 2) res = max(res, i - j + 1);
            }
            for(int j = i; j >= last; j--) freq[a[j]]--;
        }
    }

    cout << res << '\n';
}