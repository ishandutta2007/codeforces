#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] -= x;
    }
    ll ans = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        int s1 = a[i];
        if(s1 > 0) {
            ans += n - 1 - i;
            continue;
        }
        int tg = 1 - s1;
        if(a[n - 1] < tg)
            continue;
        int lo = i + 1, hi = n - 1;
        while(lo < hi) {
            int mi = (lo + hi)/2;
            if(a[mi] >= tg)
                hi = mi;
            else
                lo = mi + 1;
        }
        ans += (n - lo);
    }
    cout << ans << '\n';
}