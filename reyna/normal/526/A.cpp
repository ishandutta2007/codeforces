//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
typedef long long ll;
const long long Mod = 1e9 + 7;
const int Maxf = 1e6 + 9;
ll f[Maxf];
ll pw(ll a,ll b){
    return b?(pw((a * a)%Mod,b >> 1) * (b & 1?a:1))%Mod:1;
}
inline ll C(ll k,ll n){
    if(k < 0 || n < 0 || k > n) return 0;
    if(n < Maxf) return (f[n] * pw((f[k]*f[n-k])%Mod,Mod-2))%Mod;
    ll cur = 1,div = 1;
    For(i,0,k) div *= i + 1,cur *= n - i,div %= Mod,cur %= Mod;
    return (cur * pw(div,Mod-2)) % Mod;
}
ll gcd(ll a,ll b){
    return (a >= b)?(b?gcd(b,a%b):a):gcd(b,a);
}
inline void init(){
    f[0] = 1;
    for(ll i = 1; i < Maxf;i++)
        f[i] = (f[i-1] * i) % Mod;
    return;
}
int main(){
    init();
    int n;
    cin >> n;
    string S;
    cin >> S;
    for(int i = 1; i < n;i++){
        for(int j = 0; j < n;j++){
            int cnt = 0;
            if(S[j] != '*')
                continue;
            for(int k = 1;j + k * i < n && k <= 4;k++)
                if(S[j + k * i] == '*')
                    cnt++;
            if(cnt >= 4){
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}