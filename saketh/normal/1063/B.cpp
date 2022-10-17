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

    int N, M, R, C, X, Y;
    cin >> N >> M >> R >> C >> X >> Y;
    R--, C--;


    vvi mm(N, vi(M, -1));
    mm[R][C] = 0;

    string row;
    for (int i = 0; i < N; i++) {
        cin >> row;
        for (int j = 0; j < M; j++)
            if (row[j] == '*')
                mm[i][j] = INT_MAX;
    }

    int ans = 0;
    priority_queue<tuple<int, int, int, int, int>> dij;
    dij.push({ 0, 0, 0, R, C });

    while (!dij.empty()) {
        int dist, left, right, locx, locy;
        tie(dist, left, right, locx, locy) = dij.top();
        dist *= -1;
        dij.pop();
        ans++;

        if (locx > 0 && mm[locx-1][locy] == -1) {
            mm[locx-1][locy] = dist;
            dij.push({ -dist, left, right, locx-1, locy });
        }
        if (locx+1 < N && mm[locx+1][locy] == -1) {
            mm[locx+1][locy] = dist;
            dij.push({ -dist, left, right, locx+1, locy });
        }
        if (locy > 0 && mm[locx][locy-1] == -1 && left < X) {
            mm[locx][locy-1] = dist+1;
            dij.push({ -(dist+1), left+1, right, locx, locy-1 });
        }
        if (locy+1 < M && mm[locx][locy+1] == -1 && right < Y) {
            mm[locx][locy+1] = dist+1;
            dij.push({ -(dist+1), left, right+1, locx, locy+1 });
        }
    }

    cout << ans << endl;
    return 0;
}