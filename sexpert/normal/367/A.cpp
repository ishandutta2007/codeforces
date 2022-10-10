#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 +  5;
int ctx[MAXN], cty[MAXN], ctz[MAXN];

int main() {
    string s;
    cin >> s;
    for(int i = 1; i <= s.length(); i++) {
        ctx[i] = ctx[i - 1];
        cty[i] = cty[i - 1];
        ctz[i] = ctz[i - 1];
        if(s[i - 1] == 'x')
            ctx[i]++;
        if(s[i - 1] == 'y')
            cty[i]++;
        if(s[i - 1] == 'z')
            ctz[i]++;
    }
    int m;
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        int nx = ctx[r] - ctx[l - 1], ny = cty[r] - cty[l - 1], nz = ctz[r] - ctz[l - 1];
        int amt = (r - l + 1)/3;
        if(r - l + 1 < 3) {
            cout << "YES\n";
            continue;
        }
        if(nx < amt || nx > amt + 1 || ny < amt || ny > amt + 1 || nz < amt || nz > amt + 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}