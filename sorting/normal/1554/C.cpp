#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        ++m;
        int ans = 0;
        for(int i = 30; i >= 0; --i){
            bool b_n = (n >> i) & 1;
            bool b_m = (m >> i) & 1;
            if(b_n && !b_m) break;
            if(b_n != b_m) ans += 1 << i;
        }
        cout << ans << "\n";
    }
}