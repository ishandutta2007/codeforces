#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> a >> b >> c;
    a = min(a, b + c);
    b = min(b, a + c);
    c = min(c, a + b);
    cout << a + b +  c;
    return 0;
}