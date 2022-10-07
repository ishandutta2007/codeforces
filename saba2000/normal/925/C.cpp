#include<bits/stdc++.h>
#define ll long long
#define fr first
#define se second
using namespace std;
vector<ll> v[70];
main(){
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        ll b = 0;
        for (ll j =60 ;j >= 0; j--)
        if((((ll)1) << j)&a)
            {b = j; break;}
        v[b].push_back(a);
    }
    //010101010
    vector<ll > ans, ans1;
    for (ll i = 59; i >= 0; i--){
        ll C = 0;
        for (ll j = 0; j < ans.size(); j++){
            if(C < v[i].size() && (ans[j] & (((ll)1)<<i))) ans1.push_back(v[i][C]),C++;
            ans1.push_back(ans[j]);
        }
        for (ll j = C; j < v[i].size(); j++)
            ans1.push_back(v[i][C]);
        ans = ans1;
        ans1.clear();
    }
     ll S =0;
    for (int i=0; i <ans.size(); i++){
    if((ans[i] ^ S) <= S){
        cout<<"No"<<endl;
        return 0;
    }
    S^=ans[i];}

    cout<<"Yes"<<endl;
    for (ll i= 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
/*
100000
*/