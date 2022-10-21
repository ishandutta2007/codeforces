#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n;
int a[N];
int sdif[N][105];
int sfreq[N][105];
vi pos[N];
const int INF = (int)1e9;
int topos[N];

bool good(int l, int r) {
    int mxf = 0, cnt = 0;
    rep(i, 0, 100) mxf = max(mxf, sfreq[l][i] - sfreq[r + 1][i]);
    rep(i, 0, 100) cnt += (sfreq[l][i] - sfreq[r + 1][i]) == mxf;
    return cnt >= 2;
}

mt19937 rng(23333);
int la[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
//        a[i]--;
        a[i]--;
//
//        a[i] = rng() % 5;

        topos[i] = sz(pos[a[i]]);
        pos[a[i]].push_back(i);
    }
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < 100; j++) sfreq[i][j] = sfreq[i + 1][j] + (a[i] == j);
    }
//    fill(sdif[n + 1], sdif[n + 1] + 100, -INF);
    memset(la, -1, sizeof(la));
    for(int i = n; i >= 2; i--) {
        for(int j = 0; j < 100; j++) {
            sdif[i][j] = sfreq[i][a[i - 1]] - sfreq[i][j];
            if(i < n) {
                if(la[a[i - 1]] != -1 && la[a[i - 1]] < n) {
                    sdif[i][j] = max(sdif[la[a[i - 1]] + 1][j], sdif[i][j]);
                }
//                sdif[i][j] = max(sdif[i][j], sdif[i + 1][j]);
            }
//            if(j < 5) cout << i << ", " << j << " " << sdif[i][j] << endl;
        }
        la[a[i]] = i;
    }
    int res = 0;
    for(int i = n; i >= 2; i--) {
        int mxf = -1, mxa = -1, mxb = -1;
        rep(j, 0, 100) mxf = max(mxf, sfreq[i][j]);
        rep(j, 0, 100) {
            if(mxf != sfreq[i][j]) continue;
            if(mxa == -1) mxa = j;
            else {
                mxb = j;
                break;
            }
        }
        if(mxb != -1) {
            res = max(res, n - i + 1);
            continue;
        }
        if(mxa != a[i - 1]) continue;
        int mxpos = -1;
        rep(j, 0, 100) {
            int v = a[i - 1];
            if(v == j) continue;
            int l = topos[i - 1] + 1, r = sz(pos[v]), mid;
            int thres = mxf - sfreq[i][j];
            while(l + 1 < r) {
                mid = (l + r) / 2;
                if(sdif[pos[v][mid] + 1][j] + 1 >= thres) l = mid;
                else r = mid;
            }
//            if(i == 3 && j <= 4) {
//                cout << i << " " << j << " " << pos[v][l] << endl;
//            }

//            if(pos[v][l] == 8) cout << thres<< " " << j << ": " << pos[v][l] << endl;
            mxpos = max(mxpos, pos[v][l]);
        }
//        cout << i << " " << mxpos << endl;
        res = max(res, mxpos - i);
    }
    for(int i = 1; i <= n; i++) {
        if(good(1, i)) res = max(res, i);
    }
//    int rres = 0;
//    for(int i = 1; i <= n; i++) {
//        for(int j = i; j <= n; j++) {
//            if(good(i, j)) rres = max(rres, j - i + 1);
//        }
//    }
    cout << res << '\n';

}