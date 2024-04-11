#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    int ans = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        int cur = 0, x = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == c)
                cur++;
            else
                cur = 0;
                
            if(cur == k){
                cur = 0;
                x++;
            }
        }
        
        ans = max(ans, x);
    }
    
    
    cout << ans;
}