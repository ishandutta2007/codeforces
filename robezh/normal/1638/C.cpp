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
typedef pair<int, int> P;

const int N = (int)1e5 + 50;

int n;
int p[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> p[i], p[i]--;
        vector<pii> S;
        for (int i = n - 1; i >= 0; i--) {
            pii v = {p[i], p[i]};
            while(!S.empty() && S.back().first <= p[i]) {
                auto vb = S.back(); S.pop_back();
                v.first = min(vb.first, v.first);
                v.second = max(vb.second, v.second);
            }
            S.push_back(v);
        }
        cout << sz(S) << '\n';
    }
}