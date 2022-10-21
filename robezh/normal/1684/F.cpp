#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2
const int N = (int)2e5 + 50, INF = (int)1e9;

int n, m, a[N];
vi add[N], del[N];
vi a2[N], d2[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) {
            add[i].clear(), del[i].clear();
            a2[i].clear(), d2[i].clear();
        }
        map<int, vi> oc;
        rep(i, 0, n) cin >> a[i], oc[a[i]].push_back(i);
        rep(i, 0, m) {
            int l, r; cin >> l >> r; l--, r--;
            if(l - 1 >= 0) del[l - 1].push_back(r);
            add[r].push_back(r);
        }
        multiset<int> S;
        int mnb = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int x : add[i]) S.insert(x);
            for (int x : del[i]) S.erase(S.find(x));
            if(S.empty()) continue;
            int r = *S.rbegin();
            auto &vs = oc[a[i]];
            int il = lower_bound(all(vs), i) - vs.begin();
            int ir = lower_bound(all(vs), r + 1) - vs.begin() - 1;
            if(il == ir) continue;
            mnb = max(mnb, vs[ir - 1]);
            a2[vs[ir - 1]].push_back(vs[il]);
            d2[vs[ir]].push_back(vs[il]);
            a2[vs[ir]].push_back(vs[il + 1]);
//            cout << "catching " << a[i] << " " << il << ", " << ir << endl;
        }

        int res = n;
        S.clear();
        for (int i = 0; i < n; i++) {
            for (int x : a2[i])  S.insert(x);
            for (int x : d2[i])  S.erase(S.find(x));
            if(i >= mnb) {
                if(S.empty()) res = 0;
                else res = min(res, i - *S.begin() + 1);
            }
        }
        cout << res << '\n';
    }


}