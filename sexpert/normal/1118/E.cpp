#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ll n, k;
    cin >> n >> k;
    if(n > k*(k - 1ll)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int sp = 2, c1 = 1, c2;
    for(int i = 0; i < n; i++) {
        cout << c1++ << " ";
        if(c1 > k)
            c1 -= k;
        if(i % k == 0)
            c2 = sp++;
        cout << c2++ << '\n';
        if(c2 > k)
            c2 -= k;
    }
}