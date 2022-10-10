#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int msk = 0; msk < (1 << n); msk++) {
        int d = 0;
        for(int i = 0; i < n; i++) {
            if(msk & (1 << i))
                d += a[i];
            else
                d -= a[i];
        }
        if(abs(d) % 360 == 0) {
            cout << "YES\n";
            return 0;
        }
    }    
    cout << "NO\n";
    return 0;
}