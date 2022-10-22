#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    ll n, b;
    cin >> n >> b;
    b = b * 8 / n;
    ll s = 1;
    for(int i = 0; i < b; i++){
        s *= 2;
        if(s >= n){
            cout << 0 << endl;
            return 0;
        }
    }
    ll a[400005];
    map<ll, ll> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<ll> v;
    for(auto itr = mp.begin(); itr != mp.end(); itr++) v.push_back(itr -> second);
    ll l = v.size();
    if(l <= s){
        cout << 0 << endl;
        return 0;
    }
    ll now = 0;
    for(int i = 0; i < s; i++) now += v[i];
    ll ans = now;
    for(int i = s; i < l; i++){
        now += v[i] - v[i - s];
        ans = max(ans, now);
    }
    cout << n - ans << endl;
}