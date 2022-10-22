#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using li = long long;

const li M = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    s += 'a';

    int n = s.length();

    vector<li> f(n + 1);
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i < f.size(); i++) {
        f[i] = (f[i  - 1] + f[i - 2]) % M;
    }

    bool is = false;
    for(auto c : s)
        is |= (c == 'w') || (c == 'm');

    if(is) {
        cout << 0;
        return 0;
    }

    li ans = 1;
    int cn = 0, cu = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] !='n') {
            ans = ans * f[cn] % M;
            cn = 0;
        }
        if(s[i] != 'u') {
            ans = ans * f[cu] % M;
            cu = 0;
        }
        if(s[i] == 'n') {
            cn++;
        } else if(s[i] == 'u') {
            cu++;
        }
    }

    cout << ans;
}