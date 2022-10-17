#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll N, X, Y, H;

ll hitsby(double t, ll F){
    return floor(F * t);
}

int main(){
    cin >> N >> X >> Y;
    for(ll i=0; i<N; i++){
        cin >> H;
        H %= (X + Y);
        if(H == 0){ cout << "Both\n"; continue; }

        double lo = 0, hi = 1;
        while((hi - lo) > min(1.0/X, 1.0/Y)/2.0){
            double mi = (hi + lo)/2;
            ll hits = hitsby(mi, X) + hitsby(mi, Y);
            if(hits >= H) hi = mi;
            else lo = mi;
        }

        ll hx = hitsby(hi, X);
        ll hy = hitsby(hi, Y);
        
        if(hx+hy == H){ //want the last hit in the range
            if(hx * Y == hy * X) cout << "Both\n";
            else if(hx * Y > hy * X) cout << "Vanya\n";
            else cout << "Vova\n";
        }
        else{ //two hits in range, want the lower one 
            if(hx * Y == hy * X) cout << "Both\n";
            else if(hx * Y > hy * X) cout << "Vova\n";
            else cout << "Vanya\n";
        }
    }

    cout.flush();
    return 0;
}