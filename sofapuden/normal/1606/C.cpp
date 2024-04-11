#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
fg:
    while(t--){
        ll n, k; cin >> n >> k;
        vector<ll> v(n);
        for(auto &x : v)cin >> x;
        sort(v.begin(),v.end());
        string s;
        for(int i = 0; i < n-1; ++i){
            int mx = 1;
            for(int j = v[i]; j < v[i+1]; ++j){
                mx*=10;
            }
            mx--;
            if(k < mx){
                reverse(s.begin(),s.end());
                cout << k+1 << s << '\n';
                goto fg;
            }
            else{
                s+=to_string(mx);
                k-=mx;
            }
        }
        reverse(s.begin(),s.end());
        cout << k+1 << s << '\n';
    }
}