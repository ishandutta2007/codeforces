#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c;
ll res = 0;


int main() {
    cin >> a >> b >> c;
    if(a > b) res = 2 * b + 1 + 2 * c;
    else if(a == b) res = a + b + 2 * c;
    else if(a < b) res = 2 * a + 1 + 2 * c;
    cout << res << endl;
}