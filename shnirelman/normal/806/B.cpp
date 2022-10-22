//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 5;
const int L = 6;

mt19937 rnd(time(0));

int a[N][K];
int mn[K][L];
int cnt[K];

//int calc(vector<int> cost) {
//    if(cost.size() == K) {
//        int res = 0;
//        for(int i = 0; i < K; i++)
//            res = max(res, mn[i][cost[i]]);
//
//        int x[2] = {0, 0};
//        for(int i = 0; i < K; i++) {
//            for(int j = 0; j < 2; j++) {
//                x[j] += (cost[i] + 1) * (500 - 2 * a[j][i]);
//            }
//        }
//
//        if(x[0] > x[1])
//            return res;
//        else
//            return INF;
//    }
//
//    int res = INF;
//    cost.push_back(0);
//    for(; cost.back() < L; cost.back()++) {
//        res = min(res, calc(cost));
//    }
//
//    return res;
//}

int get(int x, int y) {
    for(int l = 5; l >= 0; l--) {
        if(x * (1ll << l) <= y)
            return l;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < K; j++) {
            cin >> a[i][j];
            if(a[i][j] != -1)
                cnt[j]++;
        }
    }

    int lf = -1, rg = INF;
    for(int m = 0; m <= 1e5; m++) {

        li x[2] = {0, 0};
        for(int i = 0; i < K; i++) {
            if(a[0][i] < a[1][i] || a[1][i] == -1 || a[0][i] == -1) {
                int l = get(cnt[i], n + m);
//                cout << "low " << i << ' ' << l << endl;
                for(int j = 0; j < 2; j++) {
                    if(a[j][i] != -1)
                        x[j] += (l + 1) * 1ll * (500 - 2 * a[j][i]);
                }
            } else {
                int l = get(cnt[i] + m, n + m);
//                cout << "great " << i << ' ' << l << endl;
                for(int j = 0; j < 2; j++) {
                    if(a[j][i] != -1)
                        x[j] += (l + 1) * 1ll * (500 - 2 * a[j][i]);
                }
            }
        }

//        cout << lf << ' ' << m << ' ' << rg << ' ' << x[0] << ' ' << x[1] << endl;

        if(x[0] > x[1]) {
            cout << m << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}