#include <bits/stdc++.h>

using namespace std;

int main() {
    int case_cnt; cin >> case_cnt;
    while (case_cnt--) {
        int n, x, y;
        cin >> n >> x >> y;
        
        bool win = false;
        
        for (int i = 1; i <= x; ++i) {
            int t; cin >> t;
            if (t == n) {
                win = true;
            }
        }
        for (int i = 1; i <= y; ++i) {
            int t; cin >> t;
        }
        
        puts(win ? "YES" : "NO");
    }
    
    return 0;
}