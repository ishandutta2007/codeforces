#include <bits/stdc++.h>

#define ff first
#define ss second
#define y1 yy1

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll b = -1, e = -1, n;
string s, t;
ll a1 = 1, a2 = 1;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    cin >> s >> t;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            b = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
            e = i;

    for (int i = b; i < e; i++) {
        if (s[i] != t[i + 1])
            a1 = 0;
        if (s[i + 1] != t[i])
            a2 = 0;
    }

    cout << a1 + a2;

    return 0;
}