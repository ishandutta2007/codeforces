#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;

const int N = (int)1e6 + 50;

mt19937_64 rng(23333);
int n;
ull h[N], v[N];
int bad[N];
int p[N];

void output(vi res) {
    for(int x : res) bad[x] = 1;
    cout << n - sz(res) << '\n';
    rep(i, 1, n + 1) {
        if(!bad[i]) cout << i << " ";
    }
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    h[0] = 1;
    ull fp = 0;
    iota(p, p + n + 1, 0);
    rep(i, 2, n + 1) {
        if(p[i] == i) {
            for (int j = i * 2; j <= n; j += i) p[j] = i;
//            cout << i << " ";
        }
    }
//    cout << endl;
    h[0] = 1;
    rep(i, 1, n + 1) {
        if(i == 1) v[i] = 1;
        else if(p[i] == i) v[i] = rng();
        else v[i] = v[i / p[i]] ^ v[p[i]];
        h[i] = h[i - 1] ^ v[i];
        fp ^= h[i];
    }
    if(fp == 0) output({});
    map<ull, int> mp;
    rep(i, 1, n + 1) mp[h[i] ^ fp] = i;
    if(mp.find(0) != mp.end()) {
        output({mp[0]});
    }
    rep(i, 1, n + 1) {
        if(mp.find(h[i]) != mp.end()) {
            output({i, mp[h[i]]});
        }
    }

    output({2, (n - 1) / 2, n});


}