#include <bits/stdc++.h>
using namespace std;
const int N = 100005, N2 = N * 4, INF = 0x3c3c3c3c;
const int Wab[3] = {1, -1, 0};
const int Wbc[3] = {0, 1, -1};
const int Wans[3] = {1, 0, -1};
int n, q, cc, ab[N2], bc[N2], ans[N2], lazy[N2][3];
char s[100005];

void update(int x, int add, int l, int r, int pos) {
    if (x > r) return;
    if (x <= l) {
        int kt = s[x] - 'a';
        lazy[pos][kt] += add;
        ab[pos] += Wab[kt] * add;
        bc[pos] += Wbc[kt] * add;
        ans[pos] += Wans[kt] * add;
        return;
    }
    int mid = (l+r) / 2;
    update(x, add, l, mid, pos*2);
    update(x, add, mid+1, r, pos*2+1);

    ab[pos] = min(ab[pos*2], ab[pos*2+1]) + lazy[pos][0] - lazy[pos][1];
    bc[pos] = min(bc[pos*2], bc[pos*2+1]) + lazy[pos][1] - lazy[pos][2];
    ans[pos] = min(min(ans[pos*2], ans[pos*2+1]), ab[pos*2] + bc[pos*2+1]) + lazy[pos][0] - lazy[pos][2];
}

void update(int x, int add) {
    if (s[x] == 'c') cc += add;
    update(x, add, 0, n, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q >> s + 1;

    for(int i=1; i<=n; ++i) update(i, 1);
    int x;
    char c;
    while (q--) {
        cin >> x >> c;
        update(x, -1);
        s[x] = c;
        update(x, 1);
        cout << ans[1] + cc << '\n';
    }
}