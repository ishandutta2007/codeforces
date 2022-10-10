#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
 
    ll c2 = 0;
    ll n;
    int q;
    cin >> q;
    while(q--) {
        cin >> n;
        ll moves = 0;
        ll ct2 = 0;
        while(n % 5 == 0) {
            ct2 += 2;
            n /= 5;
            moves++;
        }
        while(n % 3 == 0) {
            ct2++;
            n /= 3;
            moves++;
        }
        while(n % 2 == 0) {
            n /= 2;
            ct2++;
        }
        if(n == 1)
            cout << moves + ct2 << '\n';
        else
            cout << "-1\n";
    }
}