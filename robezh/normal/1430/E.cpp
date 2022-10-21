#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n;
string str;
vector<int> pos[256];
int bit[N];
int loc[N];

void add(int x, int val) {
    for(int i = x; i < n; i |= i + 1) bit[i] += val;
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}


int main() {
    cin >> n >> str;
    rep(i, 0, n) pos[(int)(str[i] - 'a')].push_back(i);
    rep(c, 0, 26) {
        for(int i = 0; i < sz(pos[c]); i++) {
            loc[n - 1 - pos[c][i]] = pos[c][sz(pos[c]) - 1 - i];
        }
    }
    ll res = 0;
    for(int i = n - 1; i >= 0; i--) {
        res += get(loc[i] - 1);
        add(loc[i], 1);
    }
    cout << res << '\n';
}