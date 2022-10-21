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

const int N = (int)2e6 + 50;

struct Manacher {
    string s, sn;
    int p[2*N];

    int Init() {
        int len = s.length();
        sn = "$#";
        rep(i, 0, len) {
            sn.push_back(s[i]);
            sn.push_back('#');
        }
        sn.push_back('\0');
        return sn.length();
    }

    int run() {
        int len = Init();
        int max_len = -1, id = 0, mx = 0;
        rep(i, 1, len) {
            if (i < mx) p[i] = min(p[2 * id - i], mx - i);
            else p[i] = 1;
            while (sn[i - p[i]] == sn[i + p[i]]) p[i]++;
            if (mx < i + p[i]) id = i, mx = i + p[i];
            max_len = max(max_len, p[i] - 1);
        }
        return max_len;
    }
} mnc;

int n;
string str;
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> str;
    string s;
    rep(i, 0, n) {
        s.push_back(str[i]);
        s.push_back(str[n - 1 - i]);
    }
    mnc.s = s;
    mnc.run();
//    cout << (mnc.sn) << endl;
    memset(res, -1, sizeof res);
//    rep(i, 0, sz(mnc.sn)) cout << mnc.p[i] << " ";
//    cout << endl
    for (int i = 3, j = 0; j < n / 2; j++, i += 4) {
        if(mnc.p[i] >= 2) {
            int len = (mnc.p[i] - 2) / 4;
//            cout << j << " "  << i << " " << len << " " << mnc.p[i] << " " << len * 2 + 1 << endl;
            res[j - len] = max(res[j - len], len * 2 + 1);
        }
    }
    rep(i, 0, (n + 1) / 2) {
        if(i) res[i] = max(res[i], res[i - 1] - 2);
        cout << res[i] << " ";
    }
    cout << endl;

}