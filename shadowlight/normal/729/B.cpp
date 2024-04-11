#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > data(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> data[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        bool fl = 0;
        int now_sum = 0;
        for (int j = 0; j < m; j++) {
            if (data[i][j]) {
                fl = 1;
            } else {
                now_sum++;
                if (fl) {
                    now_sum++;
                }
            }
        }
        for (int j = m - 1; j >= 0; j--) {
            if (data[i][j]) break;
            now_sum--;
        }
        if (fl) {
            sum += now_sum;
        }
    }
    for (int j = 0; j < m; j++) {
        bool fl = 0;
        int now_sum = 0;
        for (int i = 0; i < n; i++) {
            if (data[i][j]) {
                fl = 1;
            } else {
                now_sum++;
                if (fl) {
                    now_sum++;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (data[i][j]) break;
            now_sum--;
        }
        if (fl) {
            sum += now_sum;
        }
    }
    cout << sum;
}