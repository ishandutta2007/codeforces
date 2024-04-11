#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n, m;
int a[N];

bool check(ll t, vector<int> &a) {
    int rem = m;
    ll cur = 0;
    for(int i = n; i >= 1; i--) {
        if(cur >= a[i]) {
            cur -= a[i];
            continue;
        }
        a[i] -= cur;
        if(a[i] > 0 && t - i <= 0) return false;
        ll cnt = a[i] / (t - i);
        rem -= cnt;
        a[i] -= cnt * (t - i);
        if(a[i] > 0) {cur = t - (i); cur -= a[i]; a[i] = 0; rem--;}
        if(rem < 0) return false;
    }
    return true;
}

bool check(ll t) {
    vector<int> v;
    v.push_back(0);
    for(int i = 1; i <= n; i++) v.push_back(a[i]);
    return check(t, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll l = -1, r = (ll)1e18, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}