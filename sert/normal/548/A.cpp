#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

string s;
int k, n;

void fail() {
    cout << "NO\n";
    exit(0);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> s >> k;
    n = s.length();

    if (n % k) fail();

    for (int i = 0; i < n; i++) {
        //cerr << i << " " << i + (n / k) - 2 * (i % (n / k)) - 1 << "\n";
        if (s[i] != s[i + n / k - 2 * (i % (n / k)) - 1])
            fail();
    }
    cout << "YES\n";

    return 0;
}