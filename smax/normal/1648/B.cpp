#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> pref(c + 1);
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            pref[a]++;
        }
        
        for (int i=1; i<=c; i++)
            pref[i] += pref[i-1];
        
        bool ok = true;
        for (int x=1; x<=c; x++)
            if (pref[x] - pref[x-1] > 0)
                for (int i=x; i<=c; i+=x)
                    if (pref[min(i + x - 1, c)] - pref[i-1] > 0)
                        ok &= pref[i/x] - pref[i/x-1] > 0;
        cout << (ok ? "Yes" : "No") << "\n";
    }
    
    return 0;
}