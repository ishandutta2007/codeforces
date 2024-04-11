#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    vector <pii> a(n), b(m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i].first >> b[i].second;
        if(b[i].first > b[i].second) swap(b[i].first, b[i].second);
    }
    vector <int> ans;
    for(int i = 0; i < n; i ++) {
        vector <int> v;
        for(int j = 0; j < m; j ++) {
            if(a[i] == b[j]) continue;
            if(a[i].first == b[j].first || a[i].first == b[j].second) v.push_back(a[i].first);
            if(a[i].second == b[j].first || a[i].second == b[j].second) v.push_back(a[i].second);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if(v.size() > 1) {
            puts("-1");
            return 0;
        }
        for(int j = 0; j < v.size(); j ++) ans.push_back(v[j]);
    }
    swap(n, m);
    swap(a, b);
    for(int i = 0; i < n; i ++) {
        vector <int> v;
        for(int j = 0; j < m; j ++) {
            if(a[i] == b[j]) continue;
            if(a[i].first == b[j].first || a[i].first == b[j].second) v.push_back(a[i].first);
            if(a[i].second == b[j].first || a[i].second == b[j].second) v.push_back(a[i].second);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if(v.size() > 1) {
            puts("-1");
            return 0;
        }
        for(int j = 0; j < v.size(); j ++) ans.push_back(v[j]);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    if(ans.size() == 1) cout << ans[0] << endl;
    else puts("0");
}