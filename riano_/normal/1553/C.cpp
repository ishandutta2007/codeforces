#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 998244353;


// abm
long long pw(long long a,long long b,long long m){
    if(b==0) return 1;
    else if(b%2==0){
        long long x = pw(a,b/2,m);
        return (x*x)%m;
    }
    else{
        long long x = pw(a,b-1,m);
        return (a*x)%m;
    }
}



//mod
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


//Combination2
//10^6
//mod

vector<ll> fact;
vector<ll> invf;
ll comb(ll n,ll k){
    if(n<0||k<0||k>n) return 0LL;
    else{
        ll a = fact[n]*invf[k]%mod;
        a = a*invf[n-k]%mod;
        return a;
    }
}
    

int main() {
    ll T; cin >> T;
    rep(ii,T){
        string S; cin >> S;
        int sa = 0,sb = 0,ra = 5,rb = 5;
        ll ans = 10;
        rep(i,10){
            if(i%2==0){
                if(S[i]=='1'||S[i]=='?') sa++;
                ra--;
            }
            else{
                if(S[i]=='1') sb++;
                rb--;
            }
            if(sa>sb+rb){
                ans = i+1; break;
            }
        }
        sa = 0; sb = 0; ra = 5; rb = 5;
        rep(i,10){
            if(i%2==1){
                if(S[i]=='1'||S[i]=='?') sb++;
                rb--;
            }
            else{
                if(S[i]=='1') sa++;
                ra--;
            }
            if(sb>sa+ra){
                ans = min((ll)(i+1),ans); break;
            }
        }
        cout << ans << endl;
    }    
    //cout << ans << endl;
}