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
const int N = (int)1e6 + 50;
typedef bitset<N * 21> bs;

int n, m;
bs mp;
int sqf[N];
ll cnt[22];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(sqf, sqf + N, 1);
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        if(!sqf[i]) continue;
        int c = 0;
        for (ll j = i; j <= n; j *= i) {
//            cout << j << " ";
            sqf[j] = 0;
            c++;
        }
//        cout << endl;
        cnt[c]++;
    }

    ll res = 1;
    ll cur = 0;
    for (int i = 1; i < 22; i++) {
        for (int j = 1; j <= m; j++) {
            cur += !mp[i * j];
            mp[i * j] = true;
        }
        res += cur * cnt[i];
    }
    cout << res << '\n';

}