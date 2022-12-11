#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll a, b, c;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> a >> b >> c;
    c = min(c, (a + b) * 2);
    a = min(a, (b + c) * 2);
    b = min(b, (a + c) * 2);
    cout << (a + b + c) / 3;
    //return 0;
}