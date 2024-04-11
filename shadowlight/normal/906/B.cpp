#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

void rotate(vector <vector <int> > &a) {
    int n = a.size(), m = a[0].size();
    vector <vector <int> > b(m, vector <int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][n - 1 - i] = a[i][j];
        }
    }
    a = b;
}

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
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << "YES\n";
        cout << "1";
        return 0;
    }
    if (max(n, m) <= 3 && n + m < 6) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n == 3 && m == 3) {
        cout << "6 1 8\n";
        cout << "7 5 3\n";
        cout << "2 9 4\n";
        return 0;
    }
    vector <vector <int> > a(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = i * m + j + 1;
        }
    }
    bool fl = 0;
    if (n > m) {
        swap(n, m);
        rotate(a);
        fl = 1;
    }
    vector <int> white, black;
    for (int i = 0; i < n; i++) {
        for (int j = 2; j < m; j++) {
            if ((i + j) % 2 == 0) {
                white.push_back(a[i][j]);
            }
        }
    }
    if (m % 2 == 0) {
        black.push_back(a[0][m - 1]);
    } else {
        black.push_back(a[0][m - 2]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            if ((i + j) % 2 == 0) {
                white.push_back(a[i][j]);
            }
        }
        for (int j = m - 2; j <= m - 1; j++) {
            if ((i + j) % 2) {
                black.push_back(a[i][j]);
            }
        }
    }
    white.push_back(a[0][0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 2; j++) {
            if ((i + j) % 2) {
                black.push_back(a[i][j]);
            }
        }
    }
    vector <vector <int> > c(n, vector <int> (m, 0));
    int pos1 = 0, pos2 = 0;
//    for (int x : black) {
//        cout << x << " ";
//    }
//    cout << "\n";
//    for (int x : white) {
//        cout << x << " ";
//    }
//    cout << "\n";
    //cout << white.size() << " " << black.size() << "\n";
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (pos1 < (int) white.size()) {
                c[i][j] = white[pos1];
                pos1++;
            } else {
                c[i][j] = black[pos2];
                pos2++;
            }
        }
    }
    if (fl) {
        rotate(c);
        swap(n, m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}