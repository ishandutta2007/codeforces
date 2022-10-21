#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = (ll)1e9 + 7;

ll fp(ll t, ll k){
    if(k == 0) return 1;
    ll h = fp(t, k/2);
    return k%2==1 ? h*h%mod*t%mod : h*h%mod;
}

int n,m;
int s1[100050], s2[100050];

ll invM;
ll inv2;

ll calc(int i){
    if(i == n) return 0;

    if(s1[i] == 0 && s2[i] == 0)
        return (calc(i+1)*invM%mod + (m-1)*invM%mod*inv2%mod) % mod;
    else if(s1[i] == 0 && s2[i] != 0)
        return (calc(i+1)*invM%mod + (m-s2[i])*invM%mod) % mod;
    else if(s1[i] != 0 && s2[i] == 0)
        return (calc(i+1)*invM%mod + (s1[i]-1)*invM%mod) % mod;
    else{
        if(s1[i] == s2[i]) return calc(i+1)%mod;
        else if(s1[i] < s2[i]) return 0;
        else return 1;
    }
}

int main(){
    scanf("%d%d", &n, &m);

    invM = fp(m, mod-2);
    inv2 = fp(2, mod-2);

    for(int i = 0; i < n; i++) scanf("%d", &s1[i]);
    for(int i = 0; i < n; i++) scanf("%d", &s2[i]);

    cout << calc(0);
}