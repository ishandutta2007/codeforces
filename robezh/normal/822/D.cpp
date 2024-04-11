#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXA = 5e6;
const int mod = 1e9 + 7;

int t, l, r;
int p[MAXA + 50];
vector<int> prime;
int ans[MAXA + 50];

ll get(ll i){
    if(ans[i] != -1) return ans[i];
    if(p[i] == -1) return ans[i] = (i*(i-1)/2) % mod;
    ll k = p[i];
    return ans[i] = (get(i/k) + ((i/k) * ((k*(k-1)/2) % mod))) % mod;
}

int main(){
    fill(ans, ans+MAXA+50, -1);
    fill(p, p+MAXA+50, -1);
    for(int i = 2; i <= MAXA; i++){
        if(p[i] == -1){
            for(ll j = (ll)i*i; j <= MAXA; j += i)if(p[j] == -1) p[j] = i;
        }
    }
    ll res = 0;
    cin >> t >> l >> r;
    for(int i = r; i >= l; i--){
        res = (res * t) % mod;
        res = (res + get(i)) % mod;
    }
    cout << res;
}