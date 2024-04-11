#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 3;

int n, a[N], cnt[N];

bool check(int cnt_x, int cnt_other){
    if((cnt_x + cnt_other) & 1)
        return cnt_x <= cnt_other + 1;
    return cnt_x <= cnt_other;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    fill(cnt, cnt + n + 1, 0);
    for(int i = 0; i < n; ++i)
        cnt[a[i]]++;

    for(int i = 1; i <= n; ++i){
        if(cnt[i] > n / 2 + n % 2){
            cout << "-1\n";
            return;
        }
    }

    fill(cnt, cnt + n + 1, 0);
    int prev = a[0];
    vector<pair<int, int>> v;
    for(int i = 0; i < n - 1; ++i){
        if(a[i] == a[i + 1]){
            v.push_back({prev, a[i]});
            if(prev == a[i])
                cnt[prev]++;
            prev = a[i + 1];
        }
    }
    v.push_back({prev, a[n - 1]});
    if(prev == a[n - 1])
        cnt[prev]++;

    pair<int, int> mx{0, -1};
    for(int i = 1; i <= n; ++i)
        mx = max(mx, {cnt[i], i});

    if(!mx.first){
        cout << (int)v.size() - 1 << "\n";
        return;
    }

    int x = mx.second;
    int cnt_other = 0;
    for(auto p: v)
        if(p.first != x && p.second != x)
            cnt_other++;

    int ans = (int)v.size() - 1;
    while(!check(cnt[x], cnt_other)){
        ans++;
        cnt_other++;
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