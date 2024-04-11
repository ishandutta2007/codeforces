#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    li n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    int x = a.length(), y = b.length();

    int g = __gcd(x, y);

    li ans = 0;

    for(int i = 0; i < g; i++) {
        vector<int> c(256, 0);
        for(int j = i; j < y; j += g)
            c[b[j]]++;

        for(int j = i; j < x; j += g)
            ans += y / g - c[a[j]];
    }

//    cout << g << ' ' << n * g / y << endl;

    cout << n * g / y * ans;
}