#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
ll ret;
map<ll, ll> t, y;
map<pll,ll> m;

int main() {
    cin >> n;

    rep(i, n) {
	ll a, b;
	cin >> a >> b;
	++m[mp(a, b)];
	++t[a]; ++y[b];
    }


    for (auto p : t) ret += p.se * (p.se - 1) / 2;
    for (auto p : y) ret += p.se * (p.se - 1) / 2;
    for (auto p : m) ret -= p.se * (p.se - 1) / 2;
    cout << ret << endl;
    return 0;
}