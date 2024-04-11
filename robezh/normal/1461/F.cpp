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
const int N = (int)1e5 + 50;

int n, a[N];
map<char, int> s;
char res[N];
int psum[N];
ll dp[N], to[N], cost[N];

int gsum(int l, int r) {
    return psum[r] - (l == 0 ? 0 : psum[l - 1]);
}

void print_with(int thres, char c) {
    rep(i, 0, n) {
        if(i > 0 && i < thres) cout << c;
        cout << a[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(cost, cost + N, 1);

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        psum[i] = (a[i] == 1);
        if(i) psum[i] += psum[i - 1];
    }

    string str;
    cin >> str;
    for(char c : str) s[c] = 1;
    if(s.find('+') != s.end() && s.find('-') != s.end()) s.erase('-');
//    cout << s.size() << endl;
    if(s.size() == 1) {
        print_with(n, s.begin()->first);
        return 0;
    }
    if(s['-'] && s['*']) {
        int f0 = -1;
        for(int i = n - 1; i >= 0; i--) if(a[i] == 0) f0 = i;
        if(f0 == -1 || f0 == 0) {
            rep(i, 0, n) {
                cout << a[i];
                if(i < n - 1) cout << '*';
            }
        } else {
            rep(i, 0, n) {
                if(i > 0) cout << (i != f0 ? "*" : "-");
                cout << a[i];
            }
            cout << '\n';
        }

        return 0;
    }
    assert(s['+'] && s['*']);
    for(int i = 0; i < n; ) {
        if(a[i] == 0) {
            res[i] = '+';
            i++;
            continue;
        }
        res[i] = '+';
        int r = i;
        vi pos;
        ld val = 1;

        while(r < n && a[r] != 0) {
            val *= a[r];
            if(a[r] > 1) pos.push_back(r);
            r++;
        }
        int fir = i, la = r - 1;
        if(val > 100 * n) {
            rep(j, i + 1, r) {
                if(gsum(i, j - 1) == j - i || gsum(j, r - 1) == r - j) res[j] = '+';
                else res[j] = '*';
            }
            i = r;
            continue;
        }

        if(fir <= la) {
            for(int j = fir; j <= la; j++) {
                if(a[j] > 1) rep(p, fir, j + 1) cost[p] *= a[j];
                dp[j] = -1;
                for(int k = -1; k < sz(pos); k++) {
                    int p = (k == -1 ? j : pos[k]);
                    if(p > j) break;
                    ll newdp = cost[p] + (p > fir ? dp[p - 1] : 0);
                    if(newdp > dp[j]) {
                        dp[j] = newdp;
                        to[j] = p - 1;
                    }
                }

            }
            int cur = la;
            while(cur >= fir) {
                int nxtcur = to[cur];
//                cout << nxtcur << " " << cur << endl;
                rep(j, nxtcur + 2, cur + 1) res[j] = '*';
                res[nxtcur + 1] = '+';
                cur = nxtcur;
            }
        }
        i = r;
    }
    rep(i, 0, n) {
        if(i) cout << res[i];
        cout << a[i];
    }



}