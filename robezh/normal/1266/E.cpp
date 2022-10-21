#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)2e5 + 50;
ll sum = 0;

int n;
int a[N];
map<int, int> mp[N];
int cnt[N];
ll save = 0;

void add(int i, int val) {
    save -= min(a[i], cnt[i]);
    cnt[i] += val;
    save += min(a[i], cnt[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], sum += a[i];

    int q;
    cin >> q;
    while(q--) {
        int s, t, u;
        cin >> s >> t >> u;
        s--, u--;
        if(mp[s].count(t)) {
            add(mp[s][t], -1);
            mp[s].erase(t);
        }
        if(u != -1) {
            mp[s][t] = u;
            add(u, 1);
        }
        cout << sum - save << '\n';
    }
}