#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), c(n);
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        
    }
    
    for(int i = 0; i < n; i++) {
        cin >> c[i];    
        s.insert({c[i], i});
        
    }
    
    for(int i = 0; i < m; i++) {
        int t, d;
        cin >> t >> d;
        
        t--;
        
        long long res = 0;
        if(a[t] >= d) {
            a[t] -= d;
            res += d * 1ll * c[t];
            d = 0;
        } else {
            d -= a[t];
            res += a[t] * 1ll * c[t];
            // << a[t] << ' ' << c[t] << endl;
            a[t] = 0;
        }
        
        //cout << res << "  ewf ";
        
        if(a[t] == 0) {
            s.erase({c[t], t});
        }
        
        while(d > 0) {
            if(s.empty()) {
                res = 0;
                break;
            }
            
            auto [c1, i1] = *s.begin();
            if(a[i1] > d) {
                a[i1] -= d;
                res += c1 * 1ll * d;
                d = 0;
            } else {
                d -= a[i1];
                res += a[i1] * 1ll * c1;
                a[i1] = 0;
                s.erase(s.begin());
            }
        }
        
        cout << res << endl;
    }
}