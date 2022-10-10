#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 5;
int itv[MAXN], cnt[MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        v.push_back({d, i});
    }
    cin >> s;
    s += '$';
    int cur = 0;
    for(int i = 0; i < n; i++) {
        itv[i] = cur;
        if(s[i] != s[i + 1])
            cur++;
    }
    sort(v.rbegin(), v.rend());
    long long ans = 0;
    for(auto p : v) {
        long long sc = p.first;
        int pos = p.second;
        if(cnt[itv[pos]] == k)
            continue;
        cnt[itv[pos]]++;
        ans += sc;
    }
    cout << ans << endl;
}