#include <bits/stdc++.h>
 
using namespace std;
 
const int k_N = 1e5 + 3;
 
int n, x, y;
pair<int, int> b[k_N];
int before[k_N];
 
int cnt[k_N], prev_cnt[k_N], first[k_N];
set<pair<int, int>> s;
 
int ans[k_N], ans2[k_N];
 
void solve(){
    cin >> n >> x >> y;
 
    for(int i = 1; i <= n + 1; ++i)
        cnt[i] = 0;
    s.clear();
 
    for(int i = 0; i < n; ++i){
        int u;
        cin >> u;
        b[i].first = u;
        b[i].second = i;
 
        cnt[u]++;
    }
    sort(b, b + n);
 
    for(int i = 0; i < n; ++i)
        before[i] = b[i].first;
 
    for(int i = 1; i <= n + 1; ++i){
        prev_cnt[i] = cnt[i];
        s.insert({cnt[i], i});
    }
 
    for(int i = 0; i < n; ++i)
        if(i == 0 || b[i].first != b[i - 1].first)
            first[b[i].first] = i;
 
    int col;
    for(int i = 1; i <= n + 1; ++i)
        if(!cnt[i])
            col = i;
 
    for(int i = 0; i < x; ++i){
        auto it = s.rbegin();
        int idx = it->second;
        s.erase({cnt[idx], idx});
        cnt[idx]--;
        s.insert({cnt[idx], idx});
 
        b[first[idx]++].first = -1;
    }
 
    int mx = 0;
    for(int i = 1; i <= n + 1; ++i)
        mx = max((cnt[i] << 1), mx);
 
    if(mx > 2 * n - x - y){
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
 
    int mv = mx / 2;
    vector<int> v;
    for(int i = 0; i < n; ++i){
        if(b[i].first != -1)
            v.push_back(b[i].first);
    }
 
    vector<int> v2(v.size());
    for(int i = 0; i < v.size(); ++i)
        v2[(i + mv) % v.size()] = v[i];
 
    int ptr = 0;
    for(int i = 0; i < n; ++i){
        if(b[i].first == -1)
            ans[i] = before[i];
        else
            ans[i] = v2[ptr++];
    }

    //cout << "ans before: ";
    //for(int i = 0; i < n; ++i)
    //    cout << ans[i] << " ";
    //cout << "\n";

    y = n - y;
    for(int i = 0; i < n; ++i){
        if(b[i].first != -1 && ans[i] == before[i]){
            ans[i] = col;
            y--;
        }
    }

    for(int i = 0; i < n && y; ++i){
        if(b[i].first != -1 && ans[i] != col){
            ans[i] = col;
            y--;
        }
    }
 
    for(int i = 0; i < n; ++i)
        ans2[b[i].second] = ans[i];
 
    for(int i = 0; i < n; ++i)
        cout << ans2[i] << " ";
    cout << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while(t--) solve();
}