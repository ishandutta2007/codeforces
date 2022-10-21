#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;

ll x, k;

struct mat{
    ll a[2][2];
    mat(){
        for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) a[i][j] = 0;
    }
    mat(int i){
        if(i == 1){
            a[0][0] = 1, a[0][1] = 0, a[1][0] = 0, a[1][1] = 1;
        }else if(i == 2){
            a[0][0] = 2, a[0][1] = (mod+1) / 2;
            a[1][0] = 0, a[1][1] = 1;
        }
    }
};

mat times(mat x, mat y){
    mat res;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                res.a[i][j] += x.a[i][k] * y.a[k][j];
                res.a[i][j] %= mod;
            }
        }
    }
    return res;
}

mat fp(mat x, ll k){
    if(k == 0) return mat(1);
    mat hf = fp(x, k/2);
    return k % 2 ? times(times(hf, hf), x) : times(hf, hf);
}

int main(){
    cin >> x >> k;
    if(x == 0) return !printf("0");
    mat now = fp(mat(2), k);
    //mat now = mat(1);
//    for(int i = 0; i < 2; i++){
//        for(int j = 0; j < 2; j++){
//            cout << now.a[i][j] << " ";
//        }
//        cout << endl;
//    }
    ll res = (now.a[0][0] * (x % mod) % mod - now.a[0][1]) % mod;
    res = (res + mod) % mod;
    res = (res * 2) % mod;
    cout << res;
}