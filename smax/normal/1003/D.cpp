
// Problem : D. Coins and Queries
// Contest : Codeforces Round #494 (Div. 3)
// URL : https://codeforces.com/contest/1003/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, q;
    cin >> n >> q;
    vector<int> cnt(31);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        cnt[31 - __builtin_clz(a)]++;
    }
    
    while (q--) {
        int b;
        cin >> b;
        
        int ret = 0;
        for (int i=30; i>=0; i--) {
            int val = 1 << i;
            int taken = min(b / val, cnt[i]);
            ret += taken;
            b -= taken * val;
        }
        /*vector<int> cpy = cnt;
        for (int i=30; i>=0; i--)
            if (b & (1 << i)) {
                int need = 1 << i;
                for (int j=i; j>=0; j--) {
                    int val = 1 << j;
                    
                    while (need >= val && cpy[j] > 0) {
                        need -= val;
                        cpy[j]--;
                        ret++;
                    }
                    if (need == 0)
                        break;
                }
                if (need > 0) {
                    ret = -1;
                    break;
                }
                b -= need;
            }*/
        
        cout << (b > 0 ? -1 : ret) << "\n";
    }

    return 0;
}