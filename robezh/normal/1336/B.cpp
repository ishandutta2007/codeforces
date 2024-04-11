#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what_is(x) cerr << #x << " is " << x << endl;
const ll INF = (ll)4e18;

vi n;
vector<vector<int> > v;

ll p2(int x) {
    return 1LL *x * x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        n = vi(3);
        v.resize(3);
        for(int i = 0; i < 3; i++) {
            cin >> n[i];
            v[i] = vi(n[i], 0);
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < n[i]; j++) {
                cin >> v[i][j];
            }
            sort(v[i].begin(), v[i].end());
        }
        vi per = {0, 1, 2};
        ll res = INF;
        int cnt = 0;
        do {
            vi &a = v[per[0]], &b = v[per[1]], &c = v[per[2]];
            for(int i = 0; i < a.size(); i++) {
                auto j = upper_bound(b.begin(), b.end(), a[i]);
                if(j == b.begin()) continue;
                j--;
                auto k = lower_bound(c.begin(), c.end(), a[i]);
                if(k == c.end()) continue;
                res = min(res, p2(a[i] - *j) + p2(a[i] - *k) + p2(*j - *k));
            }
            cnt ++;
        } while(next_permutation(per.begin(), per.end()));
        assert(cnt == 6);
        cout << res << '\n';
    }
}