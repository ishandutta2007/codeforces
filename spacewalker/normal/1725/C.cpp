#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for (int i = (x); i < (y); i++)
typedef long long ll;
typedef vector<int> vi;
int MOD = 998244353;

int modpow(int b, int p) {
    if (p == 0) return 1;
    if (p%2 == 1) return modpow(b, p-1)* b%MOD;
    int v = modpow(b,p/2);
    return v*v%MOD;
}
int modinv(int b) {
    return modpow(b, MOD-2);
}
const int MAX = 300005;
vi fact(MAX,1);
vi invfact(MAX, 1);
int nCk(int n, int k) {
    if (k < 0 || k >  n) return 0;
    return fact[n]*invfact[n-k]%MOD*invfact[k]%MOD;
}
signed main() {
    rep(i, 1, MAX) {
        fact[i] = fact[i-1]*i%MOD;
        invfact[i] = modinv(fact[i]);
    }

    int n,m;cin>>n>>m;
    int tot = 0;
    vi arr;
    rep(i, 0, n) {
        int x;cin>>x;
        tot += x;
        arr.push_back(tot);
    }
    if (tot%2 == 1) {
        cout<<modpow(m,n);return 0;
    }
    int diameters = 0;

    set<int> mp;
    rep(i, 0, n) {
        int needed = arr[i] - tot/2;
        if (mp.find(needed) != mp.end()) diameters++;
        mp.insert(arr[i]);
    }   
    //cout<<diameters<<"..dia\n";
    if (diameters == 0) {
        cout<<modpow(m,n); return 0;
    }
    int totw = 0;
    int frees = n - diameters*2;
    rep(i, 0, diameters+1) {
        int freecol = m - i;
        int needed_cols = 0;
        if (i == diameters) {
            if (frees > 0) {
                needed_cols = 1;
            }
        } else {
            needed_cols = 2;
        }
        if (freecol < needed_cols) continue;
        int remdiameters = diameters - i;
        int wys1 = nCk(diameters, i);
        int curways = fact[m]*invfact[m-i]%MOD;
       // printf("%lld %lld\n", wys1, curways);
        int freeways = modpow(freecol, frees + remdiameters);
        int diawy2 = modpow(freecol-1, remdiameters);
        int curwy = wys1*curways%MOD*freeways%MOD*diawy2%MOD;
        //printf("%lld.......\n", curwy);
        
        totw += curwy;
        totw %= MOD;
    }
    cout<<totw;
}