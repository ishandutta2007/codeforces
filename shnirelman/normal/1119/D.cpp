#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
        
    sort(a.begin(), a.end());
    
    vector<long long> d(n, 2e18);
    for(int i = 0; i < n - 1; i++) {
        d[i] = a[i + 1] - a[i];
    }
    
    sort(d.begin(), d.end());
    //for(int i = 0; i < n; i++)
    //    cout << d[i] << ' ';
    //cout << endl;
    
    /*vector<long long> b(n), s(n + 1);
    s[0] = 0;
    for(int i = 1; i < n; i++) {
        s[i] = s[i - 1];
        s[i] += (d[i] - d[i - 1]) * (n - i);
    }*/
    
    vector<long long> s(n + 1);
    s[0] = 0;
    s[1] = (d[0]) * n;
    for(int i = 2; i <= n; i++) {
        s[i] = s[i - 1];
        s[i] += (d[i - 1] - d[i - 2]) * (n - i + 1);
    }
    
    //for(int i = 0; i <= n; i++)
    //    cout << s[i] << ' ';
    //cout << endl;
    
    int t;
    cin >> t;
    while(t--) {
        long long r, l;
        cin >> l >> r;
        
        long long q = r - l + 1;
        
        auto it = upper_bound(d.begin(), d.end(), q);
        int i = int(it - d.begin());
        
        i--;
        
        long long res = 0;
        
        if(i == -1) {
            res += q * n;
            
        } else {
            //cout << i << ' ' << d[i] << ' ' << n - i << endl;
            res += s[i + 1];
            res += (q - d[i]) * (n - i - 1);
        }
        
        cout << res << ' ';
    }
    
}