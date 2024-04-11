#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXL = 6e5;

ll triangle(ll S) {
    if(S < 0) return 0;
    return (S + 2) * (S + 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    ll V[3];
    cin >> V[0] >> V[1] >> V[2];;

    ll L;
    cin >> L;

    ll ans = 0;

    for (int H = 0; H <= MAXL; H++) {
        for (int w = 0; w < 3; w++) {
            if(V[w] > H) continue; 

            ll R = L - (H - V[w]);
            R = min(R, H + V[w] - V[0] - V[1] - V[2]);
            ans -= triangle(R);
        }
    }

    ans += (L + 1) * (L + 2) * (L + 3) / 6;
    cout << ans << endl;
}