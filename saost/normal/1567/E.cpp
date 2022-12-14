#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q, minR, a[N];
int Lft[N * 4], Rgt[N * 4];
long long res, All[N * 4];

void update(int x, int l, int r, int pos) {
    if (l == r) {
        All[pos] = 1;
        Lft[pos] = Rgt[pos] = l;
        return;
    }
    int mid = (l+r) / 2;
    if (x <= mid) update(x, l, mid, pos*2);
    else update(x, mid+1, r, pos*2+1);

    Lft[pos] = Lft[pos*2];
    Rgt[pos] = Rgt[pos*2+1];
    All[pos] = All[pos*2] + All[pos*2+1];
    if (a[mid] <= a[mid+1]) {
        if (Rgt[pos*2] == l) Lft[pos] = Lft[pos*2+1];
        if (Lft[pos*2+1] == r) Rgt[pos] = Rgt[pos*2];
        All[pos] += 1LL * (mid - Rgt[pos*2] + 1) * (Lft[pos*2+1] - mid);
    }
}

void query(int x, int y, int l, int r, int pos) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
        res += All[pos];
        if (minR && a[l - 1] <= a[l]) {
            res += 1LL * (l - minR) * (Lft[pos] - l + 1);
            if (Lft[pos] != r) minR = Rgt[pos];
        }
        else minR = Rgt[pos];
        return;
    }
    int mid = (l+r) / 2;
    query(x, y, l, mid, pos*2);
    query(x, y, mid+1, r, pos*2+1);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i], update(i, 1, n, 1);
    int type, x, y;
    while (q--) {
        cin >> type >> x >> y;
        if (type == 1) a[x] = y, update(x, 1, n, 1);
        else {
            res = minR = 0;
            query(x, y, 1, n, 1);
            cout << res << '\n';
        }
    }
}