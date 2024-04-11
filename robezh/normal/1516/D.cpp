#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)1e5 + 50, LOGN = 18;

int p[N];
int n, q, a[N];
int la[N];
vi ds[N];
int to[N][LOGN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];

    fill(p, p + N, 1);
    for(int i = 2; i < N; i++) {
        if(!p[i]) continue;
        for(int j = 2 * i; j < N; j += i) p[j] = 0;
        for(int j = i; j < N; j += i) ds[j].push_back(i);
    }
    fill(la, la + N, n);
    to[n][0] = n;
    for(int i = n - 1; i >= 0; i--) {
        to[i][0] = to[i + 1][0];

        for(int d : ds[a[i]]) {
            to[i][0] = min(to[i][0], la[d]);
        }

//        cout << i << " " << to[i][0] << endl;
        for(int d : ds[a[i]]) {
//            cout << d << " ";
            la[d] = i;
        }
//        cout << endl;
    }
    rep(b, 1, LOGN) {
        rep(i, 0, n + 1) to[i][b] = to[to[i][b - 1]][b - 1];
    }

    while(q--) {
        int l, r; cin >> l >> r; l--, r--;
        int cur = l, cnt = 0;
        for(int i = LOGN - 1; i >= 0; i--) {
            if(to[cur][i] <= r) {
//                cout << cur << " jump " << i << endl;
                cur = to[cur][i];
                cnt += (1 << i);
            }
        }
        cout << cnt + 1 << '\n';
    }



}