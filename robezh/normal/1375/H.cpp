#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = (1 << 12) + 1, B = (1 << 4), SZ = (1 << 8);
const int M = 2200050;
int cntn, n, q;
pii p[M];
vi sts[M];
int a[N];
vector<vi> idxs[B];
vi xs[B];
ll res[(1 << 16) + 5];

int add_set(int u, int v) {
    if(u == -1 || v == -1) return (u == -1 ? v : u);
    p[cntn] = {u, v};
    return cntn++;
}

vector<vi> solve(vi &ids) {
    if(ids.empty()) return {};
    if(sz(ids) == 1) {
        return {{ids[0]}};
    }
    vector<vi> res(sz(ids), vi(sz(ids), 0));
    vi ys;
    for(int i : ids) ys.push_back(a[i]);
    sort(all(ys));
    int mid = ys[(sz(ys) - 1) / 2];
    vi Lid, Rid;
    for(int i : ids) {
        if(a[i] <= mid) Lid.push_back(i);
        else Rid.push_back(i);
    }
    vector<vi> L = solve(Lid), R = solve(Rid);
    int la = 0, ra = 0;
    for(int i = 0; i < sz(ids); i++) {
        while(la < sz(Lid) && Lid[la] < ids[i]) la++;
        while(ra < sz(Rid) && Rid[ra] < ids[i]) ra++;
        int lb = 0, rb = 0;
        for(int j = i; j < sz(ids); j++) {
            while(lb < sz(Lid) && Lid[lb] <= ids[j]) lb++;
            while(rb < sz(Rid) && Rid[rb] <= ids[j]) rb++;
            if(lb > la && rb > ra) {
                res[i][j] = add_set(L[la][lb - 1], R[ra][rb - 1]);
            } else if(lb == la){
                assert(rb != ra);
                res[i][j] = R[ra][rb - 1];
            } else {
                res[i][j] = L[la][lb - 1];
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    cntn = n;
    rep(i, 0, n) {
        cin >> a[i]; a[i]--;
        xs[a[i] / SZ].push_back(i);
    }
    rep(i, 0, n) sts[i].push_back(i);
    rep(i, 0, B) {
        idxs[i] = solve(xs[i]);
    }
    rep(i, 0, q) {
        int l, r; cin >> l >> r; l--, r--;
        int curset = -1;
        rep(b, 0, B) {
            int lb = (int)(lower_bound(all(xs[b]), l) - xs[b].begin());
            int rb = (int)(upper_bound(all(xs[b]), r) - xs[b].begin());
            if(rb > lb) {
                curset = add_set(curset, idxs[b][lb][rb - 1]);
            }
        }
        res[i] = curset + 1;
    }
    cout << cntn << endl;
    rep(i, n, cntn) {
        cout << p[i].first + 1 << " " << p[i].second + 1 << "\n";
    }
    rep(i, 0, q) cout << res[i] << " ";
    cout << '\n';


}