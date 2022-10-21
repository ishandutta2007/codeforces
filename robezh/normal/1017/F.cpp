#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e8 + 15;

typedef unsigned int ll;

ll n;
ll A, B, C, D;
bitset<N/3> pm;

int id(int x){
    return (x % 2 == 0 || x % 3 == 0) ? 0 : x / 3;
}

ll fun(int x){
    return ((A * x + B) * x + C) * x + D;
}

int main(){
    cin >> n >> A >> B >> C >> D;

    ll res = 0;
    pm[0] = true;
    for(int i = 2; i <= n; i++){
        if(i >= 4 && pm[id(i)]) continue;
        for(int j = 2 * i; j <= n; j += i){
            pm[id(j)] = true;
        }
        ll fx = fun(i), cur = (ll)n;
        ll co = 0;
        while(cur > 0){co += cur / i; cur /= i;}
        res += fx * co;
    }
    cout << res << endl;

}