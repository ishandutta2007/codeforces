#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 134;

string s, k;
int n;
bool u[N][N];

void go(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= n) {
        cout << "NO\n";
        exit(0);
    }
    if (u[y][x]) {
        cout << "NO\n";
        exit(0);
    }

    u[y][x] = true;
    return;
}

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] == '#' && !u[i][j]) {
                go(i, j);
                go(i + 1, j - 1);
                go(i + 1, j + 1);
                go(i + 1, j);
                go(i + 2, j);
            }
        for (int j = 0; j < n; j++)
            if (u[i][j] && s[j] == '.') {
                cout << "NO\n";
                return 0;
            }
    }

    cout << "YES\n";

    return 0;
}