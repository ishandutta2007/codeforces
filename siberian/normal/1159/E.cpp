#include <bits/stdc++.h>
using namespace std;
 
vector<int> t, p;
 
void push(int v, int l, int r)
{
    if(p[v] == 0)
        return;
    if(r - l > 1)
    {
        p[v * 2] += p[v];
        p[v * 2 + 1] += p[v];
    }
    t[v] += (r - l) * p[v];
    p[v] = 0;
}
 
void recalc(int v)
{
    t[v] = t[v * 2] + t[v * 2 + 1];
}
 
void upd(int v, int l, int r, int L, int R, int x)
{
    push(v, l, r);
    if(l >= R || L >= r)
        return;
    if(L <= l && r <= R)
    {
        p[v] += x;
        push(v, l, r);
        return;
    }
    upd(v * 2, l, (l + r) / 2, L, R, x);
    upd(v * 2 + 1, (l + r) / 2, r, L, R, x);
    recalc(v);
}
 
int get(int v, int l, int r, int L, int R)
{
    push(v, l, r);
    if(l >= R || L >= r)
        return 0;
    if(L <= l && r <= R)
        return t[v];
    return get(v * 2, l, (l + r) / 2, L, R) + get(v * 2 + 1, (l + r) / 2, r, L, R);
}
 
 
struct node
{
    node *l, *r;
    int sz;
    int key, prior;
    node(int new_key = 0)
    {
        l = nullptr;
        r = nullptr;
        sz = 1;
        key = new_key;
        prior = rand();
    }
};
 
int sz(node *v)
{
    if(v == nullptr)
    {
        return 0;
    }
    return v->sz;
}
 
void upd_node(node *v)
{
    if(v == nullptr)
    {
        return;
    }
    v->sz = sz(v->l) + sz(v->r) + 1;
}
 
node *merge(node *root1, node *root2)
{
    if(root1 == nullptr)
    {
        return root2;
    }
    if(root2 == nullptr)
    {
        return root1;
    }
    if(root1->prior > root2->prior)
    {
        root1->r = merge(root1->r, root2);
        upd_node(root1);
        return root1;
    }
    else
    {
        root2->l = merge(root1, root2->l);
        upd_node(root2);
        return root2;
    }
}
 
pair<node*, node*> split(node *root, int key)
{
    if(root == nullptr)
    {
        return {nullptr, nullptr};
    }
    if(sz(root->l) >= key)
    {
        auto pp = split(root->l, key);
        root->l = pp.second;
        upd_node(root);
        return {pp.first, root};
    }
    else
    {
        auto pp = split(root->r, key - sz(root->l) - 1);
        root->r = pp.first;
        upd_node(root);
        return {root, pp.second};
    }
}
bool check(vector<int> &a, vector<int> &b)
{
    for(int i = 0; i < a.size(); ++i)
    {
        if(b[i] <= a.size() && b[i] - 1 >= 0 && a[b[i] - 1] <= a[i])
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    t.clear();
    p.clear();
    t.resize(4 * n);
    p.resize(4 * n);
    vector<int> next(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> next[i];
        if(next[i] != -1 && next[i] - 2 >= i + 1)
            upd(1, 0, n, i + 1, next[i] - 1, 1);
    }
    vector<int> v(n);
    node *root = nullptr;
    for(int i = 0; i < n; ++i)
    {
        v[i] = get(1, 0, n, i, i + 1);
        node *alal = new node(i + 1);
        root = merge(root, alal);
    }
    vector<int> ans(n);
    reverse(v.begin(), v.end());
 
    for(int i = 0; i < n; ++i)
    {
        auto pp = split(root, n - v[i] - i);
        auto z = split(pp.first, n - v[i] - 1 - i);
        if(z.second == nullptr)
        {
            cout << -1 << '\n';
            return;
        }
        ans[i] = z.second->key;
        root = merge(z.first, pp.second);
    }
    reverse(ans.begin(), ans.end());
    if(check(ans, next)) {
        for (auto i : ans) {
            cout << i << " ";
        }
    }
    else
        cout << -1;
    cout << '\n';
}
 
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}