#include <iostream>
#include <vector>
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
    vector<int> prime = enum_prime(100000);
    while(t--){
        ll p, q;
        cin >> p >> q;
        if(p % q){
            cout << p << endl;
            continue;
        }
        p /= q;
        ll l = q;
        ll ans = 1;
        for(int i : prime){
            if(q % i == 0){
                while(l % i == 0) l /= i;
                ll r = p;
                while(r % i == 0) r /= i;
                ans = max(ans, q / i * r);
            }
        }
        if(q > 1){
            while(p % q == 0) p /= q;
            ans = max(ans, p);
        }
        cout << ans << endl;
    }
}