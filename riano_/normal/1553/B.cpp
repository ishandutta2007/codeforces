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
        string S,S2; cin >> S >> S2;
        string ans = "No";
        rep(i,S2.size()){
            bool ok = true;
            string F = S2.substr(0,i+1);
            string B = S2.substr(i,S2.size()-i);
            reverse(B.begin(),B.end());
            ll s = min(F.size(),B.size());
            ll t = max(F.size(),B.size());
            rep(i,s){
                if(F[F.size()-1-i]!=B[B.size()-1-i]){
                    ok = false; break;
                }
            }
            if(ok){
                string U;
                if(F.size()>=B.size()) U = F;
                else U = B;
                rep(j,S.size()){
                    if(j+t-1>=S.size()) break;
                    string V = S.substr(j,t);
                    if(V==U){
                        ans = "Yes"; break;
                    }
                }
            }
        }
        cout << ans << endl;
    }    
    //cout << ans << endl;
}