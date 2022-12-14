//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 1e6 + 9;
typedef long long ll;
const ll Mod = (ll)1e16 + 9;
const ll x = 97;
ll pre1[Maxn],suf1[Maxn];
ll pre2[Maxn],suf2[Maxn];
vector<ll> s1,s2;
ll power[Maxn];
ll pw(ll a,ll b){
    return power[b];
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string S,P;
    cin >> S >> P;
    long long h1 = 0;
    power[0] = 1;
    For(i,1,Maxn)power[i] = (power[i-1] * x) % Mod;
    For(i,1,n+1){
         pre1[i] = (pre1[i-1] + pw(x,i-1) * S[i-1]) % Mod;
         pre2[i] = (pre2[i-1] + pw(x,i-1) * P[i-1]) % Mod;
    }
    for(int i = n-1; i + 1;--i){
        suf1[i] = (suf1[i+1] + pw(x,i+1) * S[i]) % Mod;
        suf2[i] = (suf2[i+1] + pw(x,i+1) * P[i]) % Mod;
    }
    ll ans = 0;
    For(ch,0,26)
        For(i,0,n+1){
            ll h1 = ((pre1[i] + suf1[i])%Mod + ((ch + 'a') * pw(x,i))%Mod)%Mod;
            ll h2 = ((pre2[i] + suf2[i])%Mod + ((ch + 'a') * pw(x,i))%Mod)%Mod;
            s1.push_back(h1);
            s2.push_back(h2);
        }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int pt = 0;
    For(i,0,s1.size()){
        if(i && s1[i] == s1[i-1])
            continue;
        while(pt != s2.size() && s2[pt] < s1[i])
            pt++;
        if(pt != s2.size() && s2[pt] == s1[i])
            ans++;
    }
//  for(set<ll>::iterator it = st.begin();it != st.end();++it)
//      if(m1[*it] && m2[*it]){
//          ans++;
//      }
    cout << ans << endl;
    return 0;
}