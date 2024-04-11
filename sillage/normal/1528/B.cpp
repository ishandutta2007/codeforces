#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
const int mod = 998244353;
int f[maxn];
int main(){
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++){
        f[i] = (f[i] + s) % mod;
        for (int j = i; j <= n; j += i) f[j] = (f[j] + 1) % mod;
        s = (s + f[i]) % mod;
    }
    cout << f[n] << endl;
}