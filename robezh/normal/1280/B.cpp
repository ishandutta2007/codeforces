#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
string str[65];

bool check(int i1, int i2, int j1, int j2) {
    for(int i = i1; i <= i2; i++) {
        for(int j = j1; j <= j2; j++) {
            if(str[i][j] != 'A') return false;
        }
    }
    return true;
}

bool check_exist(int i1, int i2, int j1, int j2) {
    for(int i = i1; i <= i2; i++) {
        for(int j = j1; j <= j2; j++) {
            if(str[i][j] == 'A') return true;
        }
    }
    return false;
}

bool have_row_col() {
    for(int i = 0; i < n; i++) {
        if(check(i, i, 0, m - 1)) return true;
    }
    for(int i = 0; i < m; i++) {
        if(check(0, n - 1, i, i)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> str[i];
        }

        if(n == 1) {
            if(check(0, n - 1, 0, m - 1)) {
                cout << "0\n";
            }
            else if(str[0][0] == 'A' || str[0][m-1] == 'A') {
                cout << "1\n";
            }
            else {
                if(check_exist(0, n - 1, 0, m - 1)) cout << "2\n";
                else cout << "MORTAL\n";
            }
        }
        else if(m == 1) {
            if(check(0, n - 1, 0, m - 1)) {
                cout << "0\n";
            }
            else if(str[0][0] == 'A' || str[n-1][0] == 'A') {
                cout << "1\n";
            }
            else {
                if(check_exist(0, n - 1, 0, m - 1)) cout << "2\n";
                else cout << "MORTAL\n";
            }
        }
        else {
            if(check(0, n - 1, 0, m - 1)) {
                cout << "0\n";
            }
            else if(check(0, 0, 0, m - 1) || check(n - 1, n - 1, 0, m - 1) ||
                    check(0, n - 1, 0, 0) || check(0, n - 1, m - 1, m - 1)) {
                cout << "1\n";
            }
            else if(str[0][0] == 'A' || str[0][m-1] == 'A' || str[n-1][0] == 'A' || str[n-1][m-1] == 'A'
                || have_row_col()) {
                cout << "2\n";
            }
            else if(check_exist(0, 0, 0, m - 1) || check_exist(n - 1, n - 1, 0, m - 1) ||
                    check_exist(0, n - 1, 0, 0) || check_exist(0, n - 1, m - 1, m - 1)) {
                cout << "3\n";
            }
            else {
                if(check_exist(0, n - 1, 0, m - 1)) cout << "4\n";
                else cout << "MORTAL\n";
            }
        }

    }
}