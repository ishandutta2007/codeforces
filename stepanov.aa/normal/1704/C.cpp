#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


#define ll long long


const ll inf = 1e18;


int32_t main(){
    if(1){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while(t--){
        ll n;
        int m;
        cin >> n >> m;
        vector<ll> a(m);
        for(int i = 0; i < m; i += 1){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<ll> b;
        b.reserve(m);
        for(int i = 0; i + 1 < m; i += 1){
            b.push_back(a[i + 1] - a[i] - 1);
        }
        b.push_back(a[0] - a[m - 1] + n - 1);
        sort(b.rbegin(), b.rend());
        ll gd = 0;
        ll tm = 0;
        for(int i = 0; i < m; i += 1){
            ll x = b[i] - tm * 2;
            if(x <= 0){

            } else if(x <= 2){
                gd += 1;
                tm += 1;
            } else{
                gd += x - 1;
                tm += 2;
            }
        }
        cout << n - gd << "\n";
    }
    return 0;
}