#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9 + 7;
ll dp[1000009];
ll s[1000009];
main(){
    string str;
    cin >> str;
    ll c = str[0], k = 1;
    ll mlt = 1;
    vector<pair<ll,ll> > v;
    for(ll i = 1; i < str.size(); i++){
        if(str[i] == c) {
            k++;
            continue;
        }
        else{
            if(v.size() == 0 && c == '0') {
                mlt = k + 1;
            }
            else
            v.push_back({k, c - '0'});
            k = 1;
            c = str[i];
        }
    }
    v.push_back({k, c - '0'});
    if(v.size() == 1){
       cout<<v[0].first*mlt % mod<<endl;
       return 0;
    }
    ll sz = 1;
    ll ans = 0;
    stack<pair<ll,ll> > S;
    for(ll i = 0; i < v.size(); i++){
        if(v[i].second == 1){
            dp[i] = sz * v[i].first % mod;
            s[i] = (s[i-1] + dp[i]) % mod;
        }
        else{
            if(i) s[i] = s[i-1];
            ll u = v[i].first;
            ll l = i, z = 0;
            while(S.size()){
                ll L = S.top().first, j = S.top().second;
                dp[i] = ((dp[i] + (s[l] - s[j]) * (u - z)) % mod + mod)% mod;
                z = L;
                l = j;
                if(L < u) S.pop();
                else break;
            }
            if(!S.size()) dp[i] = ((dp[i] + s[l] * (u - z)) % mod + mod) % mod;
            S.push({v[i].first, i});
             sz = (sz + dp[i]) % mod;
        }

    }

    if(v.back().second == 1)
        cout<<s[v.size()-1] *mlt % mod<<endl; else
    cout << (s[v.size()-1])* (v.back().first + 1) % mod * mlt % mod << endl;
}
/*


1011
11
111
101

*/