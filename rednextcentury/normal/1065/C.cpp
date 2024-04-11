#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll n, m, a, last, ans, tmp, cnt[200100], mn=1e6, mx;
int main()
{
    cin >> n >> m;
    for (ll i=0; i<n; i++){
        cin >> a;
        cnt[a]++;
        mn = min(mn, a);
        mx = max(mx, a);
    }
    for (ll i=mx; i>mn; i--){
        cnt[i]+=cnt[i+1];
    }
    for (ll i=mx; i>mn; i--){
        if (last+cnt[i]<=m) last+=cnt[i];
        else{
            ans++;
            last = cnt[i];
        }
    }
    if (last>0)
        ans++;
    cout << ans << endl;
    return 0;
}