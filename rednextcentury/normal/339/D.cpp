# include <iostream>
using namespace std;
int a[1000000];
int tree[5000000];
void build(int x, int l, int r, bool p)
{
    if (l == r)
    {
        tree[x] = a[l];
    }
    else
    {
        build(x * 2, l, (l + r) / 2, !p);
        build(x * 2 + 1, (l + r) / 2 + 1, r, !p);
        if (p)
            tree[x] = tree[x * 2] ^ tree[x * 2 + 1];
        else
            tree[x] = tree[x * 2] | tree[x * 2 + 1];
    }
}
void upd(int x, int l, int r, int v, bool p)
{
    if (l == r && r == v)
        tree[x] = a[v];
    else
    {
        if (v > r || v < l) return;
        upd(x * 2, l, (l + r) / 2, v, !p);
        upd(x * 2 + 1, (l + r) / 2 + 1, r, v, !p);
        if (p)
            tree[x] = tree[x * 2] ^ tree[x * 2 + 1];
        else
            tree[x] = tree[x * 2] | tree[x * 2 + 1];
    }
}
int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    int m = 1 << n;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    build(1, 0, m - 1, !(n%2));
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u - 1] = v;
        upd(1, 0, m - 1, u - 1, !(n % 2));
        cout << tree[1] << endl;
    }
}