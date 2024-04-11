#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

int n;
ll cur = 0, fac = 2;
ll res = 0;

int main(){
    cin >> n;
    if(n <= 2) return cout << n << endl, 0;
    for(int i = 3; i <= n; i++){
        cur = (cur + (fac - 1)) * i % mod;
        fac *= i;
        fac %= mod;
    }
    cout << (cur + fac) % mod << endl;
}