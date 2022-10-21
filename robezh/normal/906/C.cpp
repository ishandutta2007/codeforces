#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int n, m;
int nei[N];
bool cnnt[1 << N];
int full;

int get_cnt(int mask) {
    int cnt = 0;
    while(mask > 0) {
        cnt += mask % 2;
        mask /= 2;
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    if(m == n * (n - 1) / 2) return cout << 0 << endl, 0;
    full = (1 << n) - 1;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        nei[a] |= (1 << b);
        nei[b] |= (1 << a);
    }
    for(int i = 0; i < n; i++) {
        cnnt[1 << i] = true;
        nei[i] |= (1 << i);
    }
    int res = N + 1, res_mask = -1;
    for(int mask = 1; mask < (1 << n); mask++) {
        if(!cnnt[mask]) continue;
        int adj = 0;
        for(int j = 0; j < n; j++) if((mask >> j) & 1) adj |= nei[j];
        for(int j = 0; j < n; j++) {
            if((adj >> j) & 1) cnnt[mask | (1 << j)] = true;
        }
        int cnt = get_cnt(mask);
        if(adj == full && cnt < res) {
            res = cnt;
            res_mask = mask;
        }
    }
    cout << res << endl;
    for(int i = 0; i < n; i++) if((res_mask >> i) & 1) cout << i + 1 << " ";
    cout << endl;
}