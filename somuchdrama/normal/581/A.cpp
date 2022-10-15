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
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    int dif = a - b;
    cout << (a - dif) << ' ' << (dif / 2);
    
    return 0;
}