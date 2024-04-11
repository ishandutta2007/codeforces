#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll h[MAXN], nfree[MAXN];

int main() {
    ll n, s;
    cin >> n >> s;
    if(s < 2*n - 1 || s > n*(n + 1ll)/2ll) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    ll cs = n*(n + 1ll)/2ll;
    ll mxlev = n, mnfree = 1, bf = 1;
    for(int i = 1; i <= n; i++)
        h[i] = 1;
    for(ll mbf = 1;;mbf++) {
        ll ms = 0, bfp = 1, ren = n;
        for(ll i = 1; ren > 0; i++) {
            ms += i*min(bfp, ren);
            ren -= min(bfp, ren);
            bfp *= mbf;
        }
        if(ms <= s) {
            bf = mbf;
            break;
        }
    }
    while(cs > s) {
        ll ml = 1;
        bool done = false;
        for(int lv = 1; lv < n; lv++) {
            if(h[lv] < ml && cs - s >= mxlev - lv) {
                done = true;
                while(h[mxlev] > 0 && h[lv] < ml && cs - s >= mxlev - lv) {
                    cs -= mxlev;
                    cs += lv;
                    h[mxlev]--;
                    h[lv]++;
                }
                if(h[mxlev] == 0)
                    mxlev--;
                break;
            }
            ml *= bf;
            if(ml > 1e7)
                ml = 1e7;
        }
    }
    int ifst = 1;
    for(int i = 2; i <= mxlev; i++) {
        int cnt = 0, cn = ifst;
        for(int j = 0; j < h[i]; j++) {
            if(cnt >= bf) {
                cnt = 0;
                cn++;
            }
            cout << cn << " ";
            cnt++;
        }
        ifst += h[i - 1];
    }
    cout << endl;
}