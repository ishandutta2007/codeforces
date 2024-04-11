//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 5000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int fi = -1, fj = -1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 'F')
                fi = i, fj = j;

    vector<vector<int>> b(n, vector<int>(m, -1));
    queue<pii> q;
    q.push({fi, fj});

    while(!q.empty()) {
        int i = q.front().f, j = q.front().s;
        q.pop();

        for(int k = 0; k < 4; k++) {
            int i1 = i + di[k], j1 = j + dj[k];
            if(0 <= i1 && i1 < n && 0 <= j1 && j1 < m && a[i1][j1] != '*' && b[i1][j1] == -1) {
                b[i1][j1] = k;
                q.push({i1, j1});
            }
        }
    }

    int rg = -1, dw = -1;
    int i = 0, j = 0;
    while(a[i][j] != 'F') {
        int i1, j1;
//        cout << b[i][j] << ' ' << rg << ' ' << dw << endl;
        if(b[i][j] % 2 == 0) {
            if(dw == -1) {
                cout << "D" << endl;
                cin >> i1 >> j1;
                i1--;
                j1--;

                if(i1 == i)
                    dw = 1;
                else
                    dw = 0;
            } else {
                if(b[i][j] == 2)
                    cout << (dw == 0 ? "U" : "D") << endl;
                else
                    cout << (dw == 1 ? "U" : "D") << endl;

                cin >> i1 >> j1;
                i1--;
                j1--;
            }
        } else {
            if(rg == -1) {
                cout << "R" << endl;
                cin >> i1 >> j1;
                i1--;
                j1--;

                if(j1 == j)
                    rg = 1;
                else
                    rg = 0;
            } else {
                if(b[i][j] == 3)
                    cout << (rg == 0 ? "L" : "R") << endl;
                else
                    cout << (rg == 1 ? "L" : "R") << endl;

                cin >> i1 >> j1;
                i1--;
                j1--;
            }
        }

        i = i1;
        j = j1;
    }
}