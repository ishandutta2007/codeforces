#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];
    multiset <int> s;
    for(int i = 1; i <= n; i ++) s.insert(-abs(a[i]-b[i]));
    x += y;
    while(x --) {
        int x = *s.begin();
        s.erase(s.begin());
        s.insert(-abs(x+1));
    }
    long long ans = 0;
    for(auto i : s) ans += 1ll * i * i;
    cout << ans << endl;
}