#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

std::vector<int> enum_prime(int n){     // containing n
    std::vector<int> res;
    if (n <= 1) return res;
    std::vector<bool> p(n + 1);
    fill(p.begin() + 2, p.end(), true);
    for(int i = 2; i <= n; i++){
        if(p[i]){
            res.push_back(i);
            for(int j = i * 2; j <= n; j += i) p[j] = false;
        }
    }
    return res;
}

map<int, int> mp[200005];

ll foo(int p, int n){
    if((int)mp[p].size() == n){
        int c = 100;
        for(auto itr = mp[p].begin(); itr != mp[p].end(); itr++) c = min(c, itr->second);
        for(int i = 0; i < n; i++){
            if(mp[p][i] == c) mp[p].erase(i);
            else mp[p][i] -= c;
        }
        ll res = 1;
        for(int i = 0; i < c; i++) res = res * p % MOD;
        return res;
    }
    return 1;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> prime = enum_prime(200000);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        for(int p : prime){
            if(p > 500) break;
            while(a % p == 0){
                mp[p][i]++;
                a /= p;
            }
        }
        if(a > 1) mp[a][i]++;
    }
    ll ans = 1;
    for(int p : prime) ans = ans * foo(p, n) % MOD;
    while(q--){
        int i, x;
        cin >> i >> x;
        i--;
        for(int p : prime){
            if(p > 500) break;
            if(x % p == 0){
                while(x % p == 0){
                    mp[p][i]++;
                    x /= p;
                }
                ans = ans * foo(p, n) % MOD;
            }
        }
        if(x > 1){
            mp[x][i]++;
            ans = ans * foo(x, n) % MOD;
        }
        cout << ans << endl;
    }
}