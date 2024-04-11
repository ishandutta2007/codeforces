#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll Mod = 998244353;
const int N = 2e5 + 3;

int n, k, a[N], b[N];
int rev[N];
int prefix[N];

int get_sum(int l, int r){
    if(l > r) return 0;
    if(l == 0) return prefix[r];
    return prefix[r] - prefix[l - 1];
}

void solve(){
    for(int i = 0; i <= n + 2; ++i)
        prefix[i] = 0;

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        rev[a[i]] = i;
    }
    for(int i = 1; i <= k; ++i){
        cin >> b[i];
        b[i] = rev[b[i]];
        prefix[b[i]] = 1;
    }

    for(int i = 1; i <= n + 2; ++i)
        prefix[i] += prefix[i - 1];

    set<int> s;
    s.insert(0), s.insert(n + 1);

    ll ans = 1;
    for(int i = k; i >= 1; --i){
        int cnt_l, cnt_r;

        auto it_l = s.lower_bound(b[i]);
        it_l--;
        cnt_l = (b[i] - *it_l - 1) - get_sum(*it_l + 1, b[i] - 1);

        auto it_r = s.upper_bound(b[i]);
        cnt_r = (*it_r - b[i] - 1) - get_sum(b[i] + 1, *it_r - 1);

        //cout << b[i] << " - " << cnt_l << " " << cnt_r << "\n"; 

        cnt_l = (bool)cnt_l;
        cnt_r = (bool)cnt_r;
        ans *= (cnt_l + cnt_r);
        if(ans >= Mod) ans -= Mod;

        s.insert(b[i]);
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}