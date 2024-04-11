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

void add_res(vvi &res, vi &query, int N) {
    if (!query.size()) {
        res.push_back(vi(N, INT_MAX));
        return;
    }
        
    cout << query.size() << endl;
    for (int q : query)
        cout << q << " ";
    cout << endl;

    vi resp(N);
    for (int r = 0; r < N; r++)
        cin >> resp[r];
    res.push_back(resp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vector<vector<int>> res;

    for (int i = 0; i < 10; i++) {
        vi q1, q2;
        for (int j = 0; j < N; j++) {
            if ((j >> i)&1)
                q1.push_back(j + 1);
            else
                q2.push_back(j + 1);
        }

        add_res(res, q1, N);
        add_res(res, q2, N);
    }

    cout << -1 << "\n";
    for (int r = 0; r < N; r++) {
        int ans = INT_MAX;
        for (int i = 0; i < 10; i++) {
            if ((r >> i)&1) {
                ans = min(ans, res[2 * i + 1][r]);
            } else {
                ans = min(ans, res[2 * i][r]);
            }
        }
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}