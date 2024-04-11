#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    map<ll, int> mp;
    ll a[7002], b[7002];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<ll> v;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        if(itr -> second >= 2) v.push_back(itr -> first);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++){
        for(ll x : v){
            if((a[i] & x) == a[i]){
                ans += b[i];
                break;
            }
        }
    }
    cout << ans << endl;
}