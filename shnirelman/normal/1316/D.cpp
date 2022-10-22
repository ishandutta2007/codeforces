#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1000 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};
char ch[] = {'U', 'L', 'D', 'R'};
char inv_ch[] = {'D', 'R', 'U', 'L'};

pii a[N][N];

char c[N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j].f >> a[i][j].s;

            if(a[i][j].f != -1) {
                a[i][j].f--;
                a[i][j].s--;
            }
        }
    }

    queue<pii> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j].f == i && a[i][j].s == j) {
                c[i][j] = 'X';
                q.push({i, j});
            } else {
                c[i][j] = '-';
            }
        }
    }

    while(!q.empty()) {
        int i = q.front().f, j = q.front().s;
        q.pop();

        for(int k = 0; k < 4; k++) {
            int i1 = i + di[k], j1 = j + dj[k];

            if(min(i1, j1) < 0 || max(i1, j1) >= n)
                continue;

            if(a[i1][j1] == a[i][j] && c[i1][j1] == '-') {
                c[i1][j1] = inv_ch[k];
                q.push({i1, j1});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == pii(-1, -1)) {
                for(int k = 0; k < 4; k++) {
                    int i1 = i + di[k], j1 = j + dj[k];

                    if(min(i1, j1) < 0 || max(i1, j1) >= n)
                        continue;

                    if(a[i1][j1] == pii(-1, -1)) {
                        c[i][j] = ch[k];
                    }
                }
            }

            if(c[i][j] == '-') {
                cout << "INVALID" << endl;
                return 0;
            }
        }
    }

    cout << "VALID" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << c[i][j];
        cout << endl;
    }
}