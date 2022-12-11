#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int a;
string s, k;
int n, d;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> d >> s;
    for (int i = 0; i < n; i++) {
        if (d == 0) {
            k += s[i];
            continue;
        }
        if (s[i] <= 'm') {
            if (d <= 'z' - s[i]) {
                k += char(s[i] + d);
                d = 0;
            } else {
                d -= 'z' - s[i];
                k += 'z';
            }
        } else {
            if (d <= s[i] - 'a') {
                k += char(s[i] - d);
                d = 0;
            } else {
                d -= s[i] - 'a';
                k += 'a';
            }
        }
    }

    cout << (d ? "-1" : k);


    return 0;
}