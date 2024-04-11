#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, k, x, y;
string a[34][34], s, id;
bool pt;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    while (k--) {
        cin >> s;
        if (s[0] == '+') {
            pt = false;
            cin >> y >> x;
            cin >> id;
            //cerr << id << " ";
            for (int i = y; i <= n && !pt; i++)
                for (int j = (i == y ? x : 1); j <= m && !pt; j++)
                    if (a[i][j].length() == 0) {
                        a[i][j] = id;
                        pt = true;
                        //cerr << i << " " << j << "\n";
                    }
        } else {
            cin >> id;
            //cerr << id << "\n";
            x = y = -1;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    if (a[i][j] == id) {
                        a[i][j].clear();
                        x = j;
                        y = i;
                    }
            cout << y << " " << x << "\n";
        }
    }
}