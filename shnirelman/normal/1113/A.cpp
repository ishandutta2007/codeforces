#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    
    int ans = 0;
    int v1 = v;
    v = min(n - 1, v1);
    ans += v;
    for(int i = 1; i < n; i++) {
        
        if(n - i <= v)
            break;
        
            
        while(n - i > v && v < v1) {
            v++;
            ans += i;
        }
        
        v--;
    }
    
    cout << ans;
        
}