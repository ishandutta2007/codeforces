#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)70005;
typedef bitset<N> bs;

int n, s;
int a[N];
pii p[N];
bs dp[2], df;
int last[N];
bool used[N];
int in[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    rep(i, 0, n) cin >> a[i], p[i] = {a[i], i};
    sort(p, p + n);
    s -= p[n - 1].first;
    if(s < 0) {
        cout << -1 << endl;
        return 0;
    }



    int nw = 0, la = 1;
    dp[nw][0] = 1;
    rep(i, 0, n - 1) {
        swap(nw, la);
        dp[nw] = dp[la] | (dp[la] << p[i].first);
        df = dp[nw] ^ dp[la];
        for(int b = df._Find_first(); b != df.size(); b = df._Find_next(b)) {
            last[b] = i;
        }
//        cout << dp[nw] << endl;
    }
    if(!dp[nw][s]) {
        return cout << -1 << endl, 0;
    }
    fill(in, in + n, -1);
    int cur = s;
//    cout << "using ";
    while(cur) {
//        cout << p[last[cur]].first << " ";
        used[last[cur]] = true;
        cur -= p[last[cur]].first;
    }
//    cout << endl;
    vi idxs;
    rep(i, 0, n - 1) {
        if(!used[i]) idxs.push_back(i);
    }
    idxs.push_back(n - 1);
    rep(i, 1, sz(idxs)) {
        in[p[idxs[i]].second] = p[idxs[i - 1]].second;
    }
    rep(i, 0, n) {
        if(in[i] == -1) cout << a[i] << " " << 0 << '\n';
        else {
            cout << a[i] - a[in[i]] << " " << 1 << " " << in[i] + 1 << endl;
        }
    }





}