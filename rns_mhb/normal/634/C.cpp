#include <bits/stdc++.h>
using namespace std;

#define N 200010

int tree1[N], tree2[N];
int n, k, a, b, q, fl, d, o, p, wa[N], wb[N];
vector <int> ddd;

int query1(int i)
{
    int k, ans = 0;
    for(k = i; k > 0; k -= (k & -k))
        ans += tree1[k];
    return ans;
}
void update1(int i, int x)
{
    for(int k = i; k <= n; k += (k & -k))
        tree1[k] += (x - wa[i]);
}
void build1()
{
    int i;
    for(i = 2, tree1[1] = wa[1]; i <= n; i++) tree1[i] = tree1[i - 1] + wa[i];
    for(i = n; i >= 1; i--) tree1[i] -= tree1[i - (i & -i)];
}
int query2(int i)
{
    int k, ans = 0;
    for(k = i; k > 0; k -= (k & -k)) ans += tree2[k];
    return ans;
}
void update2(int i, int x)
{
    for(int k = i; k <= n; k += (k & -k)) tree2[k] += (x - wb[i]);

}
void build2()
{
    int i;
    for(i = 2, tree2[1] = wb[1]; i <= n; i++) tree2[i] = tree2[i - 1] + wb[i];
    for(i = n; i >= 1; i--) tree2[i] -= tree2[i - (i & -i)];
}
void maxorder() {
    int s = query1(n) - query1(p + k - 1) + query2(p - 1);
    ddd.push_back(s);
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
    build1(), build2();
    while (q -- > 0) {
        scanf("%d", &fl);
        if (fl == 1) {
            scanf("%d %d", &d, &o);
            update1(d, min(a, wa[d] + o));
            update2(d, min(b, wb[d] + o));
            wa[d] = min(a, wa[d] + o);
            wb[d] = min(b, wb[d] + o);
        }
        else scanf("%d", &p), maxorder();
    }
    for (int i = 0; i < ddd.size(); i ++) printf("%d\n", ddd[i]);

    return 0;
}