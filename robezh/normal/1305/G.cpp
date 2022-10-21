#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (1 << 18) + 5;
int n;
ll res = 0;
int f[N], sz[N], cnt[N];

int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
ll unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return 0;
    ll res = (sz[x] == 1 ? cnt[x] : 1) + (sz[y] == 1 ? cnt[y] : 1) - 1;
    sz[x] += sz[y];
    f[y] = x;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; cnt[x]++;
        res -= x;
    }
    cnt[0]++;
    for(int i = 0; i < (1 << 18); i++) f[i] = i, sz[i] = 1;
    for(int i = (1 << 18) - 1; i >= 0; i--) {
        if(cnt[i] > 0 && cnt[0] > 0) res += unite(i, 0) * i;
        for(int x = i; x; ) {
            --x &= i;
            if(cnt[x] > 0 && cnt[i ^ x] > 0) {
                res += unite(x, i ^ x) * i;
            }
            if(x * 2 < i) break;
        }
    }
    cout << res << endl;
}