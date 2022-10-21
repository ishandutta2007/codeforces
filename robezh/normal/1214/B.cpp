#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, n;

int main() {
    cin >> a >> b >> n;
    int mn = max(0, n - b);
    int mx = min(n, a);
    cout << mx - mn + 1 << endl;

}