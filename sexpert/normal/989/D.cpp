#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll l, w;

bool good(ll x1, ll x2) {
    if(x2 < x1)
        return false;
    ll center = abs(x1 + l + x2);
    ll time = x2 - x1 + l;
    return w * time > center;
}

int main() {
    cin >> n >> l >> w;
    vector<int> le, ri;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        (y == 1 ? le : ri).push_back(x);
    }
    sort(le.begin(), le.end());
    sort(ri.begin(), ri.end());
    ll ans = 0;
    for(int i = 0, j = 0; i < le.size(); i++) {
        while(j < ri.size() && !good(le[i], ri[j]))
            j++;
        ans += ri.size() - j;
    }
    cout << ans << '\n';
}