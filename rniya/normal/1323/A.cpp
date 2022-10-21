#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;++i) cin >> a[i];
        int ok=0;
        for (int i=0;i<n;++i){
            if (!(a[i]&1)){
                cout << 1 << '\n';
                cout << i+1 << '\n';
                ok=1; break;
            }
        }
        if (ok) continue;
        cout << (n==1?-1:2) << '\n';
        if (1<n) cout << 1 << ' ' << 2 << '\n';
    }
}