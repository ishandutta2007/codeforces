
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ll a, b;
    cin >> a >> b;
    if (a == 9 && b == 1) cout << "9 10" << endl;
    else if (a == b) cout << a << '0' << ' ' << b << '1' << endl;
    else if (a + 1 == b) cout << a << '9' << ' ' << b << '0' << endl;
    else cout << -1 << endl;
    return 0;
}