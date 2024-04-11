#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1e6 + 10;
vector<int> ps[MAX];
int sz[MAX], pv[2], ans[MAX], bit[MAX];

void upd(int p, int v) {
    for(; p < MAX; p += (p & -p))
        bit[p] += v;
}

int sum(int p) {
    int res = 0;
    for(; p; p -= (p & -p))
        res += bit[p];
    return res;
}

int find(int su) {
    int cur = 0;
    for(int k = 19; k >= 0; k--) {
        if(cur + (1 << k) < MAX && bit[cur + (1 << k)] <= su) {
            cur += (1 << k);
            su -= bit[cur];
        }
    }
    return cur + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pv[0] = pv[1] = -1;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] != '?')
            pv[s[i] - '0'] = i;
        sz[i] = i - min(pv[0], pv[1]);
        ps[sz[i]].push_back(i + 1);
    }
    int st = n + 1;
    upd(n + 1, 1);
    for(int cur = n; cur >= 1; cur--) {
        for(auto x : ps[cur]) {
            st = min(st, x);
            upd(x, 1);
        }
        int it = st;
        while(it <= n) {
            ans[cur]++;
            if(it + cur > n)
                break;
            it = find(sum(it + cur - 1));
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}