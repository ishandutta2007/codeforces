#include<bits/stdc++.h>
using namespace std;
main(){
    long long n;
    cin >> n;
    set<long long> Buy, Sell, Und;
    long long ans = 1;
    long long mod = 1e9+7;
    for(long long i = 1; i <= n; i++){
        string s;
        cin >> s;
        long long k;
        cin >> k;
        if(s[1] == 'D'){
            if(Buy.size() && *(Buy.begin()) < k){
                Buy.insert(k);
            }
            else
            if(Sell.size() && *(--Sell.end()) > k){
                Sell.insert(k);
            }
            else
                Und.insert(k);

        }
        else{
            if(Buy.size() && *(Buy.begin()) == k){
                Buy.erase(Buy.find(k));
                for(auto it = Und.begin(); it != Und.end(); it++){
                    if((*it) < k) Sell.insert(*it);
                    else Buy.insert(*it);
                }
                Und.clear();
            }
            else
            if(Sell.size() && *(--Sell.end()) == k){
                Sell.erase(Sell.find(k));
                for(auto it = Und.begin(); it != Und.end(); it++){
                    if((*it) < k) Sell.insert(*it);
                    else Buy.insert(*it);
                }
                Und.clear();
            }
            else
            if(Und.find(k) != Und.end()){
                ans = ans + ans;
                if(ans >= mod) ans -= mod;
                Und.erase(Und.find(k));
                for(auto it = Und.begin(); it != Und.end(); it++){
                    if((*it) < k) Sell.insert(*it);
                    else Buy.insert(*it);
                }
                Und.clear();
            }
            else{
                cout<<0<<endl;
                return 0;
            }

        }
    }
    ans = ((long long)(ans)*((long long)(Und.size() + 1))%mod);
    cout<<ans<<endl;
}