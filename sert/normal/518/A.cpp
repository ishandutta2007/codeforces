#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 2e6 + 7;

int z[N];

void z_function(string s) {
    int n = int(s.length());
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

char ss[N];
string s, t;

int main() {
    cin >> s >> t;

    int ps = s.length() - 1;
    while (s[ps] == 'z') {
        s[ps] = 'a';
        ps--;
    }
    s[ps]++;

    if (s == t) cout << "No such string\n";
    else cout << s;

    return 0;
}