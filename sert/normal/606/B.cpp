#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 800;
const ll md = 1e9 + 7;

string s;
bool u[N][N];
int x, y, sum, w, h;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> w >> h >> x >> y;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (u[y][x])
            cout << "0 ";
        else {
            cout << "1 ";
            sum++;
        }
        u[y][x] = true;
        if (s[i] == 'L') y = max(1, y - 1);
        if (s[i] == 'R') y = min(h, y + 1);
        if (s[i] == 'U') x = max(1, x - 1);
        if (s[i] == 'D') x = min(w, x + 1);
    }
    cout << w * h - sum;



    return 0;
}