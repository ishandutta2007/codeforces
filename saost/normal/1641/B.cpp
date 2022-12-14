#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 2e5 + 5;
long long t, n, x, res, a[N], Q[N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    if (n&1) { cout << -1 << '\n'; return; }
    vector<pair<int,int>> Ans;
    vector<int> Ans2;
    int tmp = 0, rr = 0, rr2 = 0;
    while (n) {
        int j = 0;
        FOR(i, 2, n) if (a[i] == a[1]) {
            j = i;
            break;
        }
        if (!j) { cout << -1 << '\n'; return; }
        REP(w, 2, j) {
            Ans.emplace_back(a[w], tmp + j + w - 2);
        }
        tmp += j * 2 - 2;
        Ans2.push_back(j * 2 - 2);
        rr = rr2 = 0;
        REP(w, 2, j) Q[++rr] = a[w];
        FORD(w, rr, 1) a[++rr2] = Q[w];
        FOR(w, j+1, n) a[++rr2] = a[w];
        n -= 2;
    }
    cout << Ans.size() << '\n';
    for(auto [u,v] : Ans) cout << v << ' ' << u << '\n';
    cout << Ans2.size() << '\n';
    for(int u : Ans2) cout << u << ' '; cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}