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
    cout << 2000 << '\n';
    for (int i = 1; i <= 1000; ++i) {
        cout << i << " 1 " << i << " 2\n";
    }
    for (int i = 1000; i >= 1; --i)
        cout << i << " 1 " << i << " 2\n";
    return 0;
}