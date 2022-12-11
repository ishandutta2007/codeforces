#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;
const int INF = (int)1e9 + 41;
//const ll INF = (ll)1e18 + 41;

bool check(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    string s;
    cin >> s;
    return (s == "YES");
}

void solve() {
    string s = "";
    int n;
    cin >> n;
    int x, y;
    x = y = 0;
    while (x + y < n - 1) {
        if (check(x, y + 1, n - 1, n - 1)) {
            s.push_back('R');
            y++;
        } else {
            s.push_back('D');
            x++;
        }
    }

    string t = "";
    x = y = n - 1;
    while (x + y > n - 1) {
        if (check(0, 0, x - 1, y)) {
            t.push_back('D');
            x--;
        } else {
            t.push_back('R');
            y--;
        }
    }
    reverse(t.begin(), t.end());
    cout << "! " << s + t << endl;
}

int main() {
#ifdef KEK
    //freopen("a.in", "r", stdin);
    //solve();
#endif // KEK
    solve();
}