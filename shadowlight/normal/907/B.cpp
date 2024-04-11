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
    #endif // MY
    char a[3][3][3][3];
    for (int i = 0; i < 3; i++) {
        string usl;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    char c;
                    cin >> c;
                    a[i][k][j][l] = c;
                    //cout << c;
                }
                //cout << " ";
            }
            //cout << "\n";
        }
        //cout << "\n";
        //cin >> usl;
    }
    int x, y;
    cin >> x >> y;
    x--, y--;
    int x1 = x / 3, x2 = x % 3, y1 = y / 3, y2 = y % 3;
    bool fl = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[x2][y2][i][j] == '.') {
                fl = 1;
                break;
            }
        }
    }
    if (!fl) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (a[i][j][k][l] == '.') {
                            a[i][j][k][l] = '!';
                        }
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[x2][y2][i][j] == '.') {
                    a[x2][y2][i][j] = '!';
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    cout << a[i][k][j][l];
                }
                cout << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}