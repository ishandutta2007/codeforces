#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
ll a, b, ans = 1;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> b >> a;
    for (int i = a + 1; i >= 1; i--) cout << i << " ";
    for (int i = a + 2; i <= a + b + 1; i++) cout << i << " ";



    return 0;
}