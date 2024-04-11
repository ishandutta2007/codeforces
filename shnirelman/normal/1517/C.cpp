#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 513;
const int LOGN = 20;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

/*

*/

mt19937 rnd(3666);

int a[N];
int res[N][N];

int n;

bool isin(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < n && i >= j);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res[i][j] = -1;
        }
    }

    for(int k = 0; k < n; k++) {
        res[k][k] = a[k];

        int i = k, j = k;

        for(int ind = 0; ind < a[k] - 1; ind++) {
            for(int l = 0; l < 4; l++) {
                int i1 = i + di[l];
                int j1 = j + dj[l];

//                cout << k << ' ' << ind << ' ' << a[k] << ' ' << i << ' ' << j << ' ' << i1 << ' ' << j1 << endl;

                if(isin(i1, j1) && res[i1][j1] == -1) {
                    i = i1;
                    j = j1;
                    res[i][j] = a[k];
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}