#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, L, R, mod = 998244353;
ll exp(ll a, ll b){
    if(!b) return 1;
    if(b &1) return a * exp(a*a%mod, (b-1)/2) % mod;
    return exp(a*a%mod,b/2) % mod;
}
main(){
    cin >> n >> m >> L >> R;
    ll a = (R - L + 1)/2, b = (R - L + 1) - a;
    if(n % 2 == 1 && m % 2 == 1){
        cout << exp(exp(a + b, n), m) << endl;
        return 0;
    }
    else{
        if(a == b){
            cout << exp(exp(a+b,n),m) * (mod+1)/2 % mod<<endl;
            return 0;
        }
        else{
            cout << (exp(exp(a+b,n),m) +mod + 1)* (mod+1)/2 % mod<<endl;
        }
    }

}
//(a+b)^2
//(a+b)^x-(a-b)^x
//O(i+1)=a*O(i)+x^i