#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi a(N), b(N);
    vi inx(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        inx[i] = i;
    }

    sort(all(inx), [&](int i, int j) {
        return a[i] < a[j];
    });

    int ans = 0;

    priority_queue<int, vi, greater<int>> ep;
    for (int i : inx) {
        ep.push(b[i]);
        while(ep.top() < a[i])
            ep.pop();

        if (ep.size() == N - 1) {
            ans = max(ans, ep.top() - a[i]);
        }
        if (ep.size() == N) {
            int del = ep.top();
            ep.pop();
            ans = max(ans, ep.top() - a[i]);
            ep.push(del);
        }
    }

    cout << ans << endl;
    return 0;
}