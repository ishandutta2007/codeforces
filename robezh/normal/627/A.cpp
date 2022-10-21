#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s,x;

bool contain(ll a, ll b){
    return (a | b) == a;
}

int main(){
    cin >> s >> x;
    ll lar = ((((ll)1<<45)-1)-x)*2;
    ll sma = s - x;
    //cout << lar << " " << sma << endl;
    if(sma < 0 || !contain(lar, sma)) return !printf("0");

    ll res = 1;
    for(int i = 0; i < 45; i++){
        if(x % 2 == 1) res *= 2;
        x /= 2;
    }
    if(sma == 0) res -= 2;
    cout << res;

}