#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        vector<int> a(n),b(n);
        for (int i=0;i<n;++i) cin >> a[i];
        for (int i=0;i<n;++i) cin >> b[i];
        for (int i=0;i<n;++i) b[i]-=a[i];
        set<int> s;
        s.emplace(0);
        int ok=1;
        for (int i=0;i<n;++i){
            if (b[i]<0&&!s.count(-1)) ok=0;
            if (0<b[i]&&!s.count(1)) ok=0;
            s.emplace(a[i]);
        }
        cout << (ok?"YES":"NO") << '\n';
    }
}