#include <bits/stdc++.h>

using namespace std;

bool isp(long long a, long long b) {
    for(int i = 0; i <= 60; i++)
        if(((a & (1ll << i)) > 0) && ((b & (1ll << i)) == 0))
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
            cin >> b[i];
            
    map<long long, vector<long long>> m;
    for(int i = 0; i < n; i++) {
        m[a[i]].push_back(b[i]);
    }
    
    long long ans = 0;
    vector<long long> c;
    for(auto [a1, b1] : m) {
        if(b1.size() > 1) {
            for(auto b2 : b1)
                ans += b2;
            c.push_back(a1);
        }
    }
    
    
    for(auto [a1, b1] : m) {
        if(b1.size() == 1) {
            for(auto c1 : c)
                if(isp(a1, c1)) {
                    //cout << a1 << ' ' << c1 << endl;
                    ans += b1[0];
                    break;
                }
        }
    }
    
    cout << ans;
    
}