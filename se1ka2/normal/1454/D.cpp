#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

vector<int> enum_prime(int n){   // containing n
    vector<int> res;
    if (n <= 1) return res;
    vector<bool> p(n + 1);
    fill(p.begin() + 2, p.end(), true);
    for(int i = 2; i <= n; i++){
        if(p[i]){
            res.push_back(i);
            for(int j = i * 2; j <= n; j += i) p[j] = false;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<int> prime = enum_prime(100000);
        map<ll, int> mp;
        for(int p : prime){
            while(n % p == 0){
                mp[p]++;
                n /= p;
            }
        }
        if(n > 1) mp[n]++;
        ll ans[200];
        int k;
        for(k = 0; k < 200; k++){
            ll s = 1;
            for(auto itr = mp.begin(); itr != mp.end(); itr++){
                if(itr->second > k) s *= itr->first;
            }
            if(s == 1) break;
            ans[k] = s;
        }
        cout << k << endl;
        for(int i = k - 1; i >= 0; i--) cout << ans[i] << " ";
        cout << endl;
    }
}