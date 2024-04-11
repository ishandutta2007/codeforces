#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009],s[200009];
string f(ll u, bool can){
    if(u == 0) return "";
    string ans = "";
    if(can){
        if(u % 9) ans += (char)(u%9 +'0');
        for(ll j = 0; j < u/9; j++)
            ans += '9';
        return ans;
    }
    else{
        if(u <= 8) {
            ans += (char)(u + '0');
            return ans;
        }
        return f(u-8, 1) + '8';
    }
}
string ans = "x";
void upd(string u){
    if(ans == "x") ans = u;
    else if(u.size() < ans.size()) ans = u;
    else if(u.size() == ans.size() && u < ans) ans = u;
}
main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        ans ="x";
        ll n, k;
        cin >> n >> k;
        for(ll d = 0; d + k <= 9; d++){
            ll u = n - (d + d + k) * (k + 1) / 2;
            if(u < 0 || u % (k + 1)) continue;
            u /= k + 1;
            upd(f(u,1) + (char)(d + '0'));
        }
        for(ll d = 10 - k; d <= 9; d++){
            for(ll n9 = 0; n9 <= 20; n9 ++){
                ll sl = 0;
                for(ll j = d; j <= d + k; j++)
                    sl += j % 10;

                ll u = n - sl - n9 * 9 * (10 - d) -  (k + 1 - (10 - d));
                if(u < 0 || u % (k+1)) continue;
                u/=(k+1);
                string x = f(u,0);
                for(ll i = 0; i < n9; i++)
                    x += '9';
                x += (char)(d + '0');

                upd(x);
            }
        }

            if(ans == "x") cout << -1 <<endl;
            else cout<<ans<<endl;
    }
}