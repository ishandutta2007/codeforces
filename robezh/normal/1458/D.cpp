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
typedef pair<int, pii> P;
const int N = (int)1e6 + 50;

int n;
string str;

struct BIT {
    int n;
    int bit[N];

    void init(int _n) {
        n = _n;
        fill(bit, bit + n, 0);
    }

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }
} bit;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> str;
        n = str.length();
        bit.init(2 * n);
        int cur = n;
        for(char c : str) {
            if(c == '1') {
                bit.add(--cur, 1);
            } else {
                bit.add(cur++, 1);
            }
        }
        cur = n;
        string res;
        while(true) {
            int ps = bit.get(cur), ps2 = bit.get(cur - 1);
            if(ps == 0) break;
            if(ps - ps2 > 1 || ps2 == 0) {
                bit.add(cur, -1);
                res.push_back('0');
                cur++;
            } else {
                cur--;
                bit.add(cur, -1);
                res.push_back('1');
            }
        }
        cout << res << '\n';

    }



}