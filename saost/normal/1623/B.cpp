#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k, res, res2, xa, xb, ya, yb;
pair<int,int> a[N];
int b[N], ans[N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i].first >> a[i].second;
}

void Process() {
    #define pii pair<int,int>
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    sort(a+1, a+n+1);
    int w = 1;
    FOR(i, 1, n) {
        while (w < a[i].first) {
            int u = Q.top().second; Q.pop();
            cout << a[u].first << ' ' << a[u].second << ' ' << w << '\n';
            ++w;
        }

        int j = i;
        while (i <= n && a[i].first == a[j].first) Q.emplace(a[i].second, i), ++i;
        --i;

    }
    while (w <= n) {
        int u = Q.top().second; Q.pop();
        cout << a[u].first << ' ' << a[u].second << ' ' << w << '\n';
        ++w;
    }
    cout << '\n';
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