#include<bits/stdc++.h>
using namespace std;

#define N 100010

char a[N], b[N];

void solve() {
    int n;
    scanf("%d%s%s", &n, a, b);
    vector <vector <int> > v(26);
    for(int i = 0; i < n; i ++) {
        if(a[i] > b[i]) {
            puts("-1");
            return;
        }
        if(a[i] < b[i]) v[a[i]-'a'].push_back(b[i]-'a');
    }
    int ans = 0;
    for(int i = 0; i < 26; i ++) if(!v[i].empty()) {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        ans ++;
        for(int j = 1; j < v[i].size(); j ++) v[v[i][0]].push_back(v[i][j]);
    }
    cout << ans << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}