#include <iostream>
using namespace std;

typedef long long ll;

ll C, HR, HB, WR, WB;

void sw(){
    swap(HB, HR);
    swap(WB, WR);
}

int main(){
    cin >> C >> HR >> HB >> WR >> WB;

    if(WB > WR)
        sw();

    if(WR * WR > C){
        ll res = 0;
        for(ll nr = 0; nr * WR <= C; nr++){
            ll nb = (C - nr * WR) / WB;
            res = max(res, nr * HR + nb * HB);
        }
        cout << res << endl;
        return 0;
    }

    if(HB * WR > WB * HR)
        sw();

    ll res = 0;
    for(ll nb = 0; nb <= WR; nb++){
        ll nr = (C - nb * WB) / WR;
        res = max(res, nr * HR + nb * HB);
    }
    cout << res << endl;
    return 0;
}