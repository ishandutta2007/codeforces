#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

const int SZ = 317;

struct Query {
    int l, r, idx;

    bool operator < (const Query &other) const {
        if (l / SZ == other.l / SZ)
            return (r < other.r) ^ (l / SZ % 2);
        return l / SZ < other.l / SZ;
    }
};

int n, a[MAX], ret[MAX], freq[MAX+1] = {};
Query queries[MAX];

int ans = 0;

void add(int i) {
    if (a[i] <= n) {
        if (freq[a[i]] == a[i])
            ans--;
        if (++freq[a[i]] == a[i])
            ans++;
    }
}

void rem(int i) {
    if (a[i] <= n) {
        if (freq[a[i]] == a[i])
            ans--;
        if (--freq[a[i]] == a[i])
            ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
    }

    sort(queries, queries + m);
    int moLeft = 0, moRight = -1;
    for (int i=0; i<m; i++) {
        while (moLeft < queries[i].l)
            rem(moLeft++);
        while (moLeft > queries[i].l)
            add(--moLeft);
        while (moRight < queries[i].r)
            add(++moRight);
        while (moRight > queries[i].r)
            rem(moRight--);
        ret[queries[i].idx] = ans;
    }

    for (int i=0; i<m; i++)
        cout << ret[i] << "\n";

    return 0;
}