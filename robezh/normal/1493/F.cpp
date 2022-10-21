#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int n, m;

int ask(int h, int w, int i1, int j1, int i2, int j2, int swp) {
    if(swp) {
        swap(h, w);
        swap(i1, j1);
        swap(i2, j2);
    }
    cout << "? " << h << " " << w << " " << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << '\n';
    fflush(stdout);
    int x; cin >> x;
    return x;
}


int solve(int swp) {
    int len = n;
    int res = 1;
    for(int i = 2; i <= len; i++) {
        if(len % i == 0) {
            int cnt = 0;
            while(len % i == 0) cnt++, len /= i;
            if(i == 2) {
                int p = 0, d = 1;
                while(p < cnt && ask(n / d / 2, m, 0, 0, n / d / 2, 0, swp))
                    p++, d *= 2;
                res *= (p + 1);
            } else {
                assert(i % 2 == 1);
                int p = 0, d = 1;
                while(true) {
                    int cb = (d * i), hf = cb / 2;
                    if(p < cnt && ask(n / cb * hf, m, 0, 0, n / cb * hf, 0, swp) &&
                            ask(n / cb * hf, m, 0, 0, n / cb * (hf + 1), 0, swp)) {
                        p++;
                        d *= i;
                    } else break;
                }
                res *= (p + 1);
            }
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    int res = solve(false);
    swap(n, m);
    res *= solve(true);
    cout << "! " << res << '\n';
    fflush(stdout);

}