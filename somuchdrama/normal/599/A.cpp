#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;




int main() {
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(min(a + b + c, a + a + b + b), min(a + a + c + c, b + b + c + c)) << '\n';

    return 0;
}