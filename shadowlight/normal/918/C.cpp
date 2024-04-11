#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // M
    string s;
    cin >> s;
    int n = s.size();
    vector <vector <bool> > can(n, vector <bool> (n, false));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((j - i) % 2) {
                can[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int bal = 0;
        bool fl = 0;
        for (int j = i; j < n; j++) {
            if (s[j] != ')') {
                bal++;
            } else {
                bal--;
            }
            if (bal < 0) {
                fl = true;
            }
            if (fl) {
                can[i][j] = false;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int bal = 0;
        bool fl = 0;
        for (int j = i; j >= 0; j--) {
            if (s[j] != '(') {
                bal++;
            } else {
                bal--;
            }
            if (bal < 0) {
                fl = true;
            }
            if (fl) {
                can[j][i] = false;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (can[i][j]) {
                res++;
                //cout << i << " " << j << "\n";
            }
        }
    }
    cout << res;
}