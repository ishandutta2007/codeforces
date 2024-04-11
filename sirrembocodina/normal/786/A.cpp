#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int s[2][7010];
int x[2][7010];
int sum[2][7010];
int n, k[2];

void add(int i, int j, int p, bool first = false) {
    if (x[i][j] < 1000 && !first) {
        return;
    }
//    cerr << i << " " << j << " " << p << endl;
    x[i][j] = p;
    if (p == -1) {
        forn (l, k[1 - i]) {
            add(1 - i, (j + n - s[1 - i][l]) % n, 1);
        }
    } else {
        forn (l, k[1 - i]) {
            int cur = (j + n - s[1 - i][l]) % n;
            sum[1 - i][cur]++;
//            cerr << "+ " << 1 - i << " " << cur << endl;
            if (sum[1 - i][cur] == k[1 - i]) {
                add(1 - i, cur, -1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> k[0];
    forn (i, k[0]) {
        cin >> s[0][i];
    }
    cin >> k[1];
    forn (i, k[1]) {
        cin >> s[1][i];
    }
    forn (i, n) {
        forn (j, 2) {
            x[j][i] = 1000;
        }
    }
    x[0][0] = x[1][0] = -1;
    add(0, 0, -1, true);
    add(1, 0, -1, true);
    forn (i, 2) {
        for (int j = 1; j < n; ++j) {
            if (x[i][j] == 1) {
                cout << "Win";
            } else if (x[i][j] == -1) {
                cout << "Lose";
            } else {
                cout << "Loop";
            }
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}