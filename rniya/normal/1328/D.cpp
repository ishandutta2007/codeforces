#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q; cin >> q;
    for (;q--;){
        int n; cin >> n;
        vector<int> t(n);
        for (int i=0;i<n;++i) cin >> t[i];
        int same=1;
        for (int i=0;i<n;++i) if (t[i]!=t[0]) same=0;
        if (same){
            cout << 1 << '\n';
            for (int i=0;i<n;++i) cout << 1 << (i!=n-1?' ':'\n');
            continue;
        }
        if (!(n&1)){
            cout << 2 << '\n';
            for (int i=0;i<n;++i) cout << (i&1)+1 << (i!=n-1?' ':'\n');
            continue;
        }
        vector<int> ans(n,1);
        int ok=0;
        for (int i=0;i<n;++i) if (t[i]==t[(i+1)%n]){
            cout << 2 << '\n'; ok=1;
            for (int j=2;j<n;++j) ans[(i+j)%n]=3-ans[(i+j-1+n)%n];
            for (int j=0;j<n;++j) cout << ans[j] << (j!=n-1?' ':'\n');
            break;
        }
        if (ok) continue;
        cout << 3 << '\n';
        ans[1]=2;
        for (int i=2;i<n;++i) ans[i]=5-ans[i-1];
        for (int i=0;i<n;++i) cout << ans[i] << (i!=n-1?' ':'\n');
    }
}