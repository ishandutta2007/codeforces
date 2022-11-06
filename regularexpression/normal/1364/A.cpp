#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        bool ok=0;
        int s=0;
        for (int i=0;i<n;++i) {
            cin >> a[i];
            s = (s+a[i])%x;
            if (a[i]%x > 0) ok = 1;
        }
        if (ok) {
            int a1=0, a2=0;
            while (a[a1]%x == 0) ++a1;
            while (a[n-a2-1]%x == 0) ++a2;
            cout << (s?n:n-min(a1, a2)-1) << '\n';
        } else
            cout << "-1\n";
    }
    return 0;
}