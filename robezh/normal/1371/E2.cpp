#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50, INF = (int)2e9;

int n, p;
int a[N];
int cnt[N];
set<int> S;
vector<pii> era;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;
    int mn = 0, mx = (int)2e9;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    rep(i, 0, n) {
        mn = max(mn, a[i] - i);
        int rem = ((a[i] - i - 1) % p + p) % p;
        cnt[rem]++;
        if((i + 1) % p == 0) mx = min(mx, a[i]);
        else {
            era.push_back({a[i] - 1, rem});
        }
    }
    reverse(all(era));
    for(int i = 0; i < p; i++) if(!cnt[i]) S.insert(i);
    int curx = mn - 1;
    vi res;
    while(true) {
        int currem = curx % p;
        int nxtrem;
        if(S.empty()) nxtrem = -1;
        else {
            auto it = S.upper_bound(currem);
            if(it == S.end()) nxtrem = p + *S.begin();
            else nxtrem = *it;
        }
        int nxtx = (nxtrem == -1 ? INF : curx / p * p + nxtrem);
        if(!era.empty() && era.back().first < nxtx) {
            int rem = era.back().second;
            cnt[rem]--;
            if(!cnt[rem]) S.insert(rem);
            curx = max(curx, era.back().first);
            era.pop_back();
            continue;
        }
        curx = nxtx;
        if(curx <= mx) res.push_back(curx);
        else break;
    }
    cout << sz(res) << '\n';
    for(int x : res) cout << x << " ";
    cout << '\n';
}