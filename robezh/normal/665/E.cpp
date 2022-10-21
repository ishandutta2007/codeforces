#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 5, K = 30;

int b[K];

struct Trie{
    int node[N * K][2], cnt[N * K];
    int sz = 1;
    int root = 0;

    void init() {
        memset(node, -1, sizeof(node));
    }

    void add(int x) {
        for(int i = 0; i < K; i++) b[i] = x % 2, x /= 2;
        int cur = root;
        cnt[cur] ++;
        for(int i = K - 1; i >= 0; i--) {
            if(node[cur][b[i]] == -1) node[cur][b[i]] = sz++;
            cur = node[cur][b[i]];
            cnt[cur] ++;
        }
    }

    int get(int x, int k) {
        for(int i = 0; i < K; i++) b[i] = x % 2, x /= 2;
        int k_bit[K];
        for(int i = 0; i < K; i++) k_bit[i] = k % 2, k /= 2;
        int cur = root;
        int res = 0;
        for(int i = K - 1; i >= 0; i--) {
            if(!k_bit[i] && node[cur][!b[i]] != -1) res += cnt[node[cur][!b[i]]];
            int nxt = node[cur][k_bit[i]^b[i]];
            cur = nxt;
            if(cur == -1) break;
        }
        if(cur != -1) res += cnt[cur];
        return res;
    }

} trie;

int n, k;
int a[N], psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    trie.init();

    cin >> n >> k;
    trie.add(0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i-1] ^ a[i];
        trie.add(psum[i]);
    }
    ll res = 0;
    for(int i = 0; i <= n; i++) {
        res += trie.get(psum[i], k);
    }
    cout << res / 2 << endl;

}