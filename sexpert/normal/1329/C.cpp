#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1 << 21], sz[1 << 21], ta[1 << 21];
vector<int> ans;
int h, g;

int valid(int p) {
    if(p >= (1 << g) || a[p] == 0)
        return 0;
    if(sz[p] == ta[p])
        return p;
    if(a[2*p] > a[2*p + 1])
        return valid(2*p);
    return valid(2*p + 1);
}

void kill(int p) {
    if(2 * p >= (1 << h) || a[2*p] + a[2*p + 1] == 0) {
        a[p] = 0;
        for(int q = p; q >= 1; q /= 2)
            sz[q]--;
        return;
    }
    if(a[2*p] > a[2*p + 1]) {
        a[p] = a[2*p];
        kill(2*p);
        return;
    }
    a[p] = a[2*p + 1];
    kill(2*p + 1);
    return;
}

void fucc(int p) {
    while(sz[p] > ta[p]) {
        int u = valid(p);
        if(u == 0) {
            ans.push_back(p);
            kill(p);
        }
        else
            fucc(u ^ 1);
    }
}

void solve() {
    cin >> h >> g;
    ans.clear();
    ta[1] = (1 << g) - 1;
    for(int i = 2; i < (1 << h); i++)
        ta[i] = ta[i / 2]/2;
    for(int i = 1; i < (1 << h); i++)
        sz[i] = 1;
    for(int i = (1 << (h - 1)) - 1; i >= 1; i--)
        sz[i] += sz[2*i] + sz[2*i + 1];
    for(int i = 1; i < (1 << h); i++)
        cin >> a[i];
    fucc(1);
    ll res = 0;
    for(int i = 1; i < (1 << g); i++)
        res += a[i];
    cout << res << '\n';
    for(auto x : ans)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}