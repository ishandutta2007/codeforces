#include <bits/stdc++.h>
using namespace std;

#define rep(i,f,t) for (int i = (f); i < (t); i++)
#define all(x) (x).begin(), (x).end()
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vi> res(N);
    rep(i,0,M) {
        rep(j,0,N) {
            int x;
            cin >> x;
            res[j].push_back(x);
        }
    }
    rep(i,0,N-1) {
        rep(j,0,M) res[i][j] -= res[N-1][j];
    }
    int mx = 0;
    vi ans;

    rep(i,0,N-1) {
        vector<pii> x;
        rep(j,0,M) x.emplace_back(res[i][j], j);
        sort(all(x), greater<pii>());

        vi tans;
        int sum = 0;
        trav(it, x) {
            if (sum + it.first >= 0) {
                sum += it.first;
                tans.push_back(it.second);
            }
        }
        if (sz(tans) > mx) {
            mx = sz(tans);
            ans = tans;
        }
    }

    cout << M - mx << endl;
    vector<bool> cancel(M, true);
    trav(it, ans) cancel[it] = false;
    rep(i,0,M) if (cancel[i]) cout << i+1 << " ";
    cout << endl;
}