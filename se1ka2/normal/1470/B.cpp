#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> prime = enum_prime(1000);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            for(int p : prime){
                while(a % (p * p) == 0) a /= p * p;
            }
            mp[a]++;
        }
        int s[2]{0};
        int c = 0;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            s[0] = max(s[0], itr->second);
            if(itr->first == 1 || itr->second % 2 == 0) c += itr->second;
        }
        s[1] = max(s[0], c);
        int q;
        cin >> q;
        while(q--){
            ll w;
            cin >> w;
            if(w == 0) cout << s[0] << "\n";
            else cout << s[1] << "\n";
        }
    }
}