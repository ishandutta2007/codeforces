#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

struct node
{
    int l, r;
    long long val;
    node(int l = 0, int r = 0, long long val = 0) : l(l), r(r), val(val){};
};

node tree[4*MAXN];
int pos[4*MAXN];
int A[MAXN];

void build(int l, int r, int id = 1)
{
    tree[id] = node(l, r);
    if(l == r)
    {
        pos[l] = id;
        tree[id].val = A[l];
    }
    else
    {
        int m = (l + r)/2;
        build(l, m, 2*id);
        build(m + 1, r, 2*id + 1);
        tree[id].val = tree[2*id].val + tree[2*id + 1].val;
    }
}

long long query(int l, int r, int id = 1)
{
    node n = tree[id];
    if(l > r || l > n.r || r < n.l)
        return 0;
    if(l <= n.l && n.r <= r)
        return n.val;
    return query(l, r, 2*id) + query(l, r, 2*id + 1);
}

int main()
{
    long long n, q, powt[MAXN];
    powt[0] = 1;
    for(int i = 1; i < MAXN; i++)
        powt[i] = (2 * powt[i - 1])%MOD;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++)
        A[i] = s[i - 1] - '0';
    build(1, n);
    for(int i = 0; i < q; i++)
    {
        int l, r, k, m;
        cin >> l >> r;
        m = r - l + 1;
        k = query(l, r);
        long long ans = (powt[m - k]*(powt[k] - 1))%MOD;
        cout << ans << endl;
    }
}