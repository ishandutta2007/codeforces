#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n;
int p[N];
int has[N];
const int B = 100;
vi big, sma;

int g(char c, int d) {
    if(d > n) {
        return 0;
    }
    cout << c << " " << d << endl;
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

void answer(int a) {
    cout << "C " << a << endl;
    fflush(stdout);
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    fill(p, p + N, 1);

    for (int i = 2; i <= n; i++) {
        if(p[i]) {
            for (int j = i * 2; j <= n; j += i) p[j] = 0;
            if(1LL * i * i <= n) sma.push_back(i);
            else big.push_back(i);
        }
    }
    int tot = n;
    fill(has + 1, has + n + 1, 1);
    int res = 1;
    for (int i = 0; i < sz(big); i += B) {
        int r = min(sz(big), i + B);
        rep(j, i, r) {
            int d = big[j];
            g('B', d);
            for (int l = d; l <= n; l += d) {
                if(has[l]) has[l] = 0, tot--;
            }
        }
        if(g('A', 1) != tot) {
            rep(j, i, r) {
                if(g('A', big[j])) {
                    res *= big[j];
                    break;
                }
            }
            break;
        }
    }
    for (int x : sma) g('B', x);
    for (int x : sma) {
        int c = x;
        while(g('A', c)) {
            res *= x;
            c *= x;
        }
    }
    answer(res);

}