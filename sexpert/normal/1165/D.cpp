#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int d;
        cin >> d;
        vector<ll> divs(d);
        for(auto &x : divs) cin >> x;
        sort(divs.begin(), divs.end());
        ll num = divs[0] * divs[d - 1];
        bool bad = false;
        int tdivs = 0;
        for(int i = 0; i < d; i++) {
            if(num % divs[i] != 0)
                bad = true;
        }
        if(bad) {
            cout << "-1\n";
            continue;
        }
        for(ll d = 2; d*d <= num; d++) {
            if(num % d == 0)
                tdivs += 2;
            if(d * d == num)
                tdivs--;
        }
        if(tdivs != d) {
            cout << "-1\n";
            continue;
        }
        cout << num << endl;
    }    
}