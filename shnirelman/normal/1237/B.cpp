#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n), p(n);
    for(int i = 0; i < n; i++) {
        int a1;
        cin >> a1;
        
        a1--;
        
        //p[a1] = 0;
        a[a1] = i;
    }
    
    for(int i = 0; i < n; i++) {
        //cout << i << ' ' << a[i] << endl;
        int b1;
        cin >> b1;
        
        b1--;
        
        b[i] = a[b1];
    }
    
    set<int> s;
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        int b1 = b[i];
        //cout << b1 << ' ' ; 
        auto it = s.upper_bound(b1);
        if(it != s.begin())
            ans++;
        
        s.insert(b1);
    }
    
    cout << ans;
 }