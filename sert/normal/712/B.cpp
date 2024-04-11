#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int)1e6 + 34;
const ll INF = 1e18;

ll n, a[N], h;
int l, r, u, d;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> s;
    if (s.length() % 2 == 1)
        cout << "-1\n";
    else {
        for (char ch: s) {
            if (ch == 'L') l++;
            if (ch == 'R') r++;
            if (ch == 'U') u++;
            if (ch == 'D') d++;
        }
        int df = abs(u - d) + abs(l - r);
        cout << df / 2;
    }
    return 0;
}