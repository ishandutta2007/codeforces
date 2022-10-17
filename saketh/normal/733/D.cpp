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

    vector<array<int, 4>> vals;

    int ans = 0;
    int u = -1, v = -1;

    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        int score = min( { x, y, z } );
        if (score > ans) {
            ans = score;
            u = i;
        }

        vector<int> v = { x, y, z };
        sort(all(v));

        do {
            vals.push_back( { v[0], v[1], v[2], i } );
        } while (next_permutation(all(v)));
    }

    sort(all(vals));

    for (int i = 1; i < vals.size(); i++) {
        if (vals[i][0] == vals[i-1][0] &&
                vals[i][1] == vals[i-1][1]) {
            int score = min( { vals[i][0], vals[i][1], vals[i-1][2] + vals[i][2] });
            if (score > ans) {
                ans = score;
                u = vals[i][3];
                v = vals[i-1][3];
            }
        }
    }

    if (v == -1) cout << "1\n" << u+1 << endl;
    else cout << "2\n" << u+1 << " " << v+1 << endl;
    return 0;
}