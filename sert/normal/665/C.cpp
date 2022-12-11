#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
typedef long long ll;
typedef long double ld;

int n, k, la = 1, lb = 1, a[N], b[N];
int ans;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> s;
    s += '#';
    for (int i = 1; i + 1 < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            s[i] = char('a' + (s[i] - 'a' + 1) % 26);
            if (s[i] == s[i + 1])
                s[i] = char('a' + (s[i] - 'a' + 1) % 26);
        }
    }

    for (int i = 0; i + 1 < s.length(); i++)
        cout << s[i];

    return 0;
}