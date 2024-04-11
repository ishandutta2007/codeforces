#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6 + 7;

string a, b;
int p[N], len, k;
long long ans;

int sum(int l, int r) {
    return p[r] - p[l];
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> a >> b;
    p[0] = 0;
    for (int i = 1; i <= b.length(); i++)
        p[i] = p[i - 1] + int(b[i - 1] == '1');

    len = b.length() - a.length() + 1;
    for (int i = 0; i < a.length(); i++) {
        k = sum(i, i + len);
        ans += (a[i] == '0' ? k : len - k);
    }
    cout << ans;


    return 0;
}