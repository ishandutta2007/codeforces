#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

int bit[MAX+1] = {};

int query(int x) {
    int ret = 0;
    for (int i=x; i>0; i-=i&-i)
        ret += bit[i];
    return ret;
}

void update(int x) {
    for (int i=x; i<=MAX; i+=i&-i)
        bit[i]++;
}

int ret[MAX], pred[MAX] = {};
vector<int> xs[MAX+1], xq[MAX+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        xs[r].push_back(l);
    }

    for (int i=0; i<m; i++) {
        int cnt;
        cin >> cnt;
        for (int j=0; j<cnt; j++) {
            int p;
            cin >> p;
            xq[p].push_back(i);
        }
        ret[i] = n;
        xq[MAX].push_back(i);
    }

    for (int x=0; x<=MAX; x++) {
        for (int i : xq[x]) {
            ret[i] -= query(x) - query(pred[i]);
            pred[i] = x;
        }
        for (int i : xs[x])
            update(i);
    }

    for (int i=0; i<m; i++)
        cout << ret[i] << "\n";

    return 0;
}