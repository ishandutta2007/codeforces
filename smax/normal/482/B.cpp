#include <bits/stdc++.h>
using namespace std;

int a[100000] = {}, pos[30][100000] = {}, L[100000], R[100000], q[100000], st[400000];

void build(int p, int l, int r) {
    if (l == r)
        st[p] = a[l];
    else {
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p] = st[2*p] & st[2*p+1];
    }
}

int query(int p, int l, int r, int i, int j) {
    if (i > r || j < l)
        return (1 << 30) - 1;
    if (i <= l && j >= r)
        return st[p];

    int m = (l + r) / 2;
    return query(2*p, l, m, i, j) & query(2*p+1, m+1, r, i, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> L[i] >> R[i] >> q[i];
        L[i]--, R[i]--;
        for (int j=0; j<30; j++)
            if (q[i] & (1 << j)) {
                pos[j][L[i]]++;
                if (R[i] < n - 1)
                    pos[j][R[i]+1]--;
            }
    }

    for (int j=0; j<30; j++)
        for (int i=0; i<n; i++) {
            if (i > 0)
                pos[j][i] += pos[j][i-1];
            if (pos[j][i] > 0)
                a[i] |= 1 << j;
        }

    build(1, 0, n-1);

    for (int i=0; i<m; i++)
        if (query(1, 0, n-1, L[i], R[i]) != q[i]) {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";

    return 0;
}