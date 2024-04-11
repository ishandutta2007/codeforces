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
const int Maxn = 1e6 + 9;
int arr[Maxn];
int n;
pair<long long,int> rec(int id){
    if(id > (1 << (n + 1)) - 1)
        return make_pair(0,0);
    int l = id << 1;
    int r = l | 1;
    long long ret = 0;
    int best = 0;;
    pair<long long,int> lans = rec(l);
    pair<long long,int> rans = rec(r);
    lans.second += arr[l];
    rans.second += arr[r];
    best = max(lans.second,rans.second);
    ret += lans.first + rans.first;
    ret += best - min(lans.second,rans.second);
    return make_pair(ret,best);
}
int main(){
    init();
    cin >> n;
    for(int i = 0; i < (1 << (n + 1)) - 2;i++){
        cin >> arr[i+2];
    }
    cout << rec(1).first << endl;
    return 0;
}