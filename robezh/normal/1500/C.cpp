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
typedef pair<vi, int> pv;
const int N = 1505;

int n, m;
int A[N][N], B[N][N];
int cnts[N];
set<int> S[N];


int sp[N], vis[N];

void split(int i) {
    sp[i] = true;
    rep(j, 0, m) {
        if(vis[j]) continue;
        if((B[i][j] <= B[i + 1][j])) {
            S[cnts[j]].erase(j);
            cnts[j]--;
            S[cnts[j]].insert(j);
//            cout << j << " to " << cnts[j] << endl;
        }
    }
}
vi res;
int pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) cin >> A[i][j];
    }
    rep(i, 0, n) {
        rep(j, 0, m) cin >> B[i][j];
    }
    rep(j, 0, m) {
        rep(i, 0, n - 1) cnts[j] += (B[i][j] <= B[i + 1][j]);
        S[cnts[j]].insert(j);
    }
    int curcnt = n - 1;
    while(curcnt && !S[curcnt].empty()) {

        int j = *S[curcnt].begin(); S[curcnt].erase(j);
        vis[j] = true;
        res.push_back(j);
        for (int i = 0; i < n - 1; i++) {
            if(!sp[i] && B[i][j] < B[i + 1][j]) {
                split(i);
                curcnt--;
//                cout << "spliting " << i << endl;
            }
        }
//        cout << curcnt << endl;
    }
    auto va = vector<pv>(n), vb = vector<pv>(n);
    rep(i, 0, n) {
        va[i] = {vi(A[i], A[i] + m), i};
        vb[i] = {vi(B[i], B[i] + m), i};
    }
    sort(all(va));
    sort(all(vb));
    rep(i, 0, n) {
        if(va[i].first != vb[i].first) {
            cout << -1 << '\n';
            return 0;
        }
        pos[vb[i].second] = va[i].second;
    }



    for (int i = 0; i < n - 1; i++) {
        if(sp[i]) continue;
        if(pos[i] > pos[i + 1]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << sz(res) << '\n';
    reverse(all(res));

    for(int x : res) cout << x + 1 << " ";
    cout << '\n';
}