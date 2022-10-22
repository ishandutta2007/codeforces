#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<int, int> m0, m1;
    //mp[0] = 1;
    m1[0] = 1;
    int p = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        p ^= a[i];
        if(i % 2 == 0) {
            ans += m0[p];
            //cout << p << ' ' << m0[p] << endl;
            if(m0.count(p))
                m0[p]++;
            else
                m0[p] = 1;
        } else {
            ans += m1[p];
            // cout << p << ' ' << m1[p] << endl;
            if(m1.count(p))
                m1[p]++;
            else
                m1[p] = 1;
            
        }
            
        
        
    }
    
    cout << ans;
}