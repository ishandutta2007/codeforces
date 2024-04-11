#include <bits/stdc++.h>

#define int int64_t

using namespace std;

const int maxn = 3e5 + 42, logn = 30;
const int max_sz = maxn * logn;
int sz = 1;
int to[max_sz][2];
int cnt[max_sz];
vector<int> nums[max_sz];

void add_num(int x, int y) {
    int v = 0;
    for(int i = logn - 1; i >= 0; i--) {
        int c = (y >> i) & 1;
        if(!to[v][c]) {
            to[v][c] = sz++;
        }
        v = to[v][c];
        cnt[v]++;
    }
}

int extract(int y) {
    int v = 0;
    int ans = 0;
    for(int i = logn - 1; i >= 0; i--) {
        int c = (y >> i) & 1;
        if(cnt[to[v][c]]) {
            v = to[v][c];
        } else {
            v = to[v][!c];
            ans |= 1 << i;
        }
        cnt[v]--;
    }
    
    return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], p[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        add_num(i, p[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << extract(a[i]) << ' ';
    }
    return 0;
}