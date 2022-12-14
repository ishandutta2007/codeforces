//In the name of God
#include <bits/stdc++.h>
using namespace std;

#define Mp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define Pb push_back
#define Err(x) cerr << #x << " = " << (x) << endl;
#define Get(a) scanf("%I64d",&a)
#define Put(a) printf("%I64d\n",a)
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int Maxn = 1e6 + 1e3;
ll sum[Maxn];
ll ten[Maxn];
ll fact[Maxn];
const int Mod = 1e9 + 7;
ll pw(ll a,ll b){
    if(!b)
        return 1;
    return (pw((a * a)%Mod,b/2) * (b%2?a:1)) % Mod;
}
ll C(int n,int k){
    if(n < k)
        return 0;
    if(n < 0 || k < 0)
        return 0;
    ll ret = fact[n];
    ret *= pw(fact[k],Mod-2);
    ret %= Mod;
    ret *= pw(fact[n-k],Mod-2);
    ret %= Mod;
    return ret;
}
int main(){
    int n,k;
    cin >> n >> k;
    string S;
    cin >> S;
    ten[0] = 1;
    For(i,1,n+1)
        ten[i] = (ten[i-1] * 10)%Mod;
    fact[0] = 1;
    For(i,1,n+1)
        fact[i] = (fact[i-1]*i)%Mod;
    For(i,0,n+1){
        ll now = 1;
        now *= ten[i];
        now %= Mod;
        now *= C(n-i-2,k-1);
        now %= Mod;
        if(i)
            sum[i] = sum[i-1];
        sum[i] += now;
        sum[i] %= Mod;
//      cerr << sum[i] << endl;
    }
    ll ans = 0;
    For(i,0,n){
        int get = n-i-2;
        ll now = 0;
        if(get >= 0){
            now += sum[get];
            now %= Mod;
            now *= S[i]-'0';
            now %= Mod;
        }
        ll add = C(i,k);
        add %= Mod;
        add *= ten[n-i-1];
        add %= Mod;
        add *= S[i]-'0';
        add %= Mod;
        now += add;
        now %= Mod;
        ans += now;
        ans %= Mod;
    }
    cout << ans << endl;
    return 0;
}