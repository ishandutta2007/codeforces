#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll inv[1000009];
ll f[1000009],fi[1000009];
ll pq[1000009], sq[1000009];
ll pr[1000009], sf[1000009];
ll mod =998244353;
ll C(int n, int m){
    if(m < 0 || n < 0 || m > n) return 0;
    return f[n] * fi[m] % mod * fi[n-m] % mod;
}
int main(){
    string s;
    int n;
    cin >> s;

    n = s.size();
    inv[1] = 1;
    for(int i = 2; i <= n; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    f[0] = 1; fi[0] = 1;
    for(int i = 1; i <= n; i++)
        f[i] = f[i-1] * i % mod,
        fi[i] =fi[i-1] * inv[i] % mod;
    pq[0] = 0;
    pr[0] = 0;
    for(int i = 0; i < s.size(); i++){
        pr[i+1] = pr[i];
        pq[i+1] = pq[i];
        if(s[i] == '(') pr[i+1]++;
        if(s[i] == '?') pq[i+1]++;
    }
    sq[s.size()+1] = 0;
    sf[s.size()+1] = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        sq[i+1] = sq[i+2];
        sf[i+1] = sf[i+2];
        if(s[i] == ')') sf[i+1]++;
        if(s[i] == '?') sq[i+1]++;
    }
    ll ans = 0;
    for(int i = 0; i <= n; i++){

        ans = (ans + pr[i] * C(pq[i] + sq[i+1], sq[i+1] + sf[i+1] - pr[i])+
                     pq[i] * C(pq[i] + sq[i+1]-1, sq[i+1] + sf[i+1] - pr[i]-1)) % mod;
}


    cout<<ans<<endl;
}
//C(