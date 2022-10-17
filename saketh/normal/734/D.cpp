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

int dir[8][2] = { {  0,  1},
                  {  1,  0},
                  {  0, -1},
                  { -1,  0},
                  {  1,  1},
                  {  1, -1},
                  { -1,  1},
                  { -1, -1} };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, X0, Y0;
    cin >> N >> X0 >> Y0;

    vector<char> near(8);
    vector<int> ndist(8, INT_MAX);

    for (int i = 0; i < N; i++) {
        char t;
        int x, y;
        cin >> t >> x >> y;
        x -= X0;
        y -= Y0;

        for (int d = 0; d < 8; d++) {
            int dist = dir[d][0] ? (x / dir[d][0]) : (y / dir[d][1]);

            if (dist < 0) continue;
            if (dist * dir[d][0] != x) continue;
            if (dist * dir[d][1] != y) continue;

            if (dist < ndist[d]) {
                ndist[d] = dist;
                near[d] = t;
            }
        }
    }

    bool attack = false;
    for (int i = 0; i < 8; i++) {
        if (near[i] == 'Q') attack = true;
        if (near[i] == 'R' && i < 4) attack = true;
        if (near[i] == 'B' && i >= 4) attack = true;

    }

    cout << (attack ? "YES" : "NO") << endl;
    return 0;
}