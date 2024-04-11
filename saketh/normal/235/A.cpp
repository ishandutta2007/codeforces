#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

ll N;

ll lcm(ll a, ll b){ return a / __gcd(a, b) * b; };

ll lcm(ll a, ll b, ll c){
    return lcm( lcm(max(a, 1ll), max(b, 1ll)), max(c, 1ll));
}

int main(){
    setup();
    cin >> N;

    if(N&1){
        cout << lcm(N, N-1, N-2) << endl;
    }
    else{
        cout << max( max( lcm(N, N-1, N-2),
                     lcm(N, N-1, N-3)),
                     lcm(N-1, N-2, N-3)) << endl;
    }
}