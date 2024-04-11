#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 50005, K = 11;

struct Group {
    vi lb, ub;
    int sz;
    Group(int *a, int *b): lb(a, b), ub(a, b) {
        sz = 1;
    }

    const bool operator < (const Group &o) const {
        rep(i, 0, sz(ub)) if(ub[i] > o.lb[i]) return false;
        return true;
    }
    void merge(set<Group>::iterator it) {
        sz += it->sz;
        rep(i, 0, sz(ub)) ub[i] = max(ub[i], it->ub[i]), lb[i] = min(lb[i], it->lb[i]);
    }
};

int n, k;
int s[N][K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    set<Group> S;
    rep(i, 0, n) {
        rep(j, 0, k) cin >> s[i][j];
        Group gp = Group(s[i], s[i] + k);
        auto st = S.lower_bound(gp);
        auto ed = S.upper_bound(gp);
        while(st != ed) {
            gp.merge(st);
            st = S.erase(st);
        }
        S.insert(gp);
        cout << S.rbegin()->sz << '\n';
    }


}