#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
int n;
string s, ss;
int l, r, k, q;

void go(int l, int r, int k) {
    for (int i = l; i < r; i++)
        ss[l + (i - l + k) % (r - l)] = s[i];
    for (int i = l; i < r; i++)
        s[i] = ss[i];
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> s;
    ss = s;
    cin >> q;
    while (q--) {
        cin >> l >> r >> k;
        k %= (r - l + 1);
        go(l - 1, r, k);
    }
    cout << s;


    return 0;
}