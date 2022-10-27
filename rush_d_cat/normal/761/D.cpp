#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int NICO = 100000 + 10;
int n, L, R;
int a[NICO], b[NICO], res[NICO], ans[NICO], pos[NICO], ok = 1;
struct Node
{
    int l, r, id;
} s[NICO];
bool cmp(Node a, Node b)
{
    return a.id < b.id;
}
int main()
{
    cin >> n >> L >> R;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        s[i].l = L - a[i];
        s[i].r = R - a[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &b[i]);
        s[i].id = b[i];pos[b[i]] = i;
    }
    sort(s+1, s+1+n, cmp);
    res[1] = s[1].l;
    for(int i=2;i<=n;i++)
    {
        res[i] = max(s[i].l, res[i-1]+1);
        if(res[i] > s[i].r) ok = 0;
    }
    if(ok == 0) {cout << -1 << endl;return 0;}
    for(int i=1;i<=n;i++)
    {
        int cur = pos[i];
        ans[cur] = a[cur] + res[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
    }
}