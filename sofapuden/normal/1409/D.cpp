#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        string s1; ll s; cin >> s1 >> s;
        reverse(s1.begin(),s1.end());
        ll ans = 0;
        for(int i = 0; i < (int)s1.size(); ++i){
            ans+=(s1[i]-'0');
        }
        if(ans <= s){
            cout << "0\n";
            continue;
        }
        ll cn = 0;
        ll tore = 0;
        ll out = 0;
        while(ans > s){
            //tore+=(s1[cn]-'0')*pow(10,cn);
            out+=((10-s1[cn]+'0'-1)%10)*pow(10,cn);
            ans-=(s1[cn]-'0');
            if(!cn)ans++;
            cn++;
        }
        cout << out+1 << "\n";
    }
}