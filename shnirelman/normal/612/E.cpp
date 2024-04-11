//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int p[N];
bool used[N];

vector<vector<int>> cyc[N];
int res[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            vector<int> q;
            int v = i;
            while(!used[v]) {
                q.push_back(v);
                used[v] = true;
                v = p[v];
            }

            cyc[q.size()].push_back(q);
        }
    }

    for(int i = 0; i <= n; i += 2) {
        if(cyc[i].size() % 2 != 0) {
            cout << -1 << endl;
            return 0;
        }

        for(int j = 0; j < cyc[i].size(); j += 2) {
            for(int k = 0; k < i; k++) {
                res[cyc[i][j][k]] = cyc[i][j + 1][k];
                res[cyc[i][j + 1][k]] = cyc[i][j][(k + 1) % i];
            }

        }
    }

    for(int i = 1; i <= n; i += 2) {
        int d = (i + 1) / 2;
        for(int j = 0; j < cyc[i].size(); j++) {
            for(int k = 0; k < i; k++) {
                res[cyc[i][j][k]] = cyc[i][j][(k + d) % i];
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << res[i] + 1 << ' ';
    cout << endl;
}