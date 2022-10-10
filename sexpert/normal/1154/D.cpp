#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b, a;
    cin >> n >> b >> a;
    int curb = b, cura = a, ans = 0;
    vector<int> seg(n);
    for(auto& x : seg) cin >> x;
    for(int i = 0; i < n; i++) {
        if(cura == 0 && curb == 0) break;
        ans++;
        if(seg[i] == 0) {
            if(cura) {
                cura--;
                continue;
            }
            curb--;
            continue;
        }
        if(seg[i] == 1) {
            if((cura == 0) || (curb > 0 && cura < a)) {
                curb--;
                cura++;
                continue;
            }
            cura--;
            continue;
        }
    }
    cout << ans << endl;
}