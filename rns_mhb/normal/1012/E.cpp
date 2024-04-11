#include<bits/stdc++.h>
using namespace std;

#define N 200010

int a[N], b[N], nxt[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i ++) cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1);
    vector <int> v;
    for(int i = 1; i <= n; i ++) if(a[i] != b[i]) v.push_back(i);
    if(v.size() > s) {
        puts("-1");
        return 0;
    }
    vector <int> u = v;
    sort(v.begin(), v.end(), [&](int i, int j) {return a[i] < a[j];});
    for(int i = 0; i < v.size(); i ++) nxt[v[i]] = u[i];
    vector <int> f(n+1);
    for(int i = 1; i <= n; i ++) f[i] = i;
    function <int(int)> find = [&](int x) {return x == f[x] ? x : f[x] = find(f[x]);};
    for(int i = 0; i < v.size(); i ++) {
        int x = find(u[i]), y = find(v[i]);
        f[x] = y;
    }
    for(int i = 0, prv = -1; i < v.size(); i ++) {
        if(a[v[i]] == prv) {
            int x = find(v[i]), y = find(v[i-1]);
            if(x != y) {
                swap(nxt[v[i]], nxt[v[i-1]]);
                f[x] = y;
            }
        }
        prv = a[v[i]];
    }
    vector <vector <int> > R;
    for(int i = 0; i < v.size(); i ++) {
        int x = v[i];
        if(vis[x]) continue;
        vector <int> r;
        while(vis[x] == 0) r.push_back(x), vis[x] = 1, x = nxt[x];
        R.push_back(r);
    }
    int k = min(s-u.size(), R.size());
    if(k <= 2) k = 0;
    int ans = R.size() - k;
    if(k > 2) ans += 2;
    cout << ans << endl;
    if(k > 2) {
        cout << 2*k << endl;
        for(int i = 0; i < k; i ++) cout << R[i][0] << ' ' << R[i][1] << ' ';
        cout << endl;
        int sum = 0;
        for(int i = 0; i < k; i ++) sum += R[i].size()-1;
        cout << sum << endl;
        for(int i = k-1; i >= 0; i --) {
            for(int j = 2; j < R[i].size(); j ++) cout << R[i][j] << ' ';
            cout << R[i][0] << ' ';
        }
        cout << endl;
    }
    for(int i = k; i < R.size(); i ++) {
        cout << R[i].size() << endl;
        for(int j = 0; j < R[i].size(); j ++) cout << R[i][j] << ' ';
        cout << endl;
    }
}