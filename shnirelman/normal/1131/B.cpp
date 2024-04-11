#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int ans = 1;
    //vector<int> a, b;
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        
        
        if(b < x || a < y) {
            
        } else {
            
            if(x != a || b != y)
                ans += min(a, b) - max(x, y) + (x != y);
        }
        
        x = a;
        y = b;
        //cout << ans << endl;
        
    }
    
    cout << ans;
}