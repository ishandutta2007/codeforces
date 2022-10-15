#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;

int n;
ll x[200005];
int ans[200005];

ll ftree[200005];

#define lowbit(i) ((i)&(-(i)))

ll query(int a)
{
    if (a < 0) return 0;
    ll answ = 0;
    while (a) {
        answ += ftree[a]; a -= lowbit(a);
    }
    return answ;
}

void modify(int a, ll amt)
{
    while (a <= n) {
        ftree[a] += amt; a += lowbit(a);
    }
}

int uf[200005];
int fin(int a);
void un(int a, int b)
{
    a = fin(a);
    b = fin(b);
    uf[a] = b;
}

int fin(int a)
{
    if (uf[a] == a)
        return a;
    return uf[a] = fin(uf[a]);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n + 1; i++) uf[i] = i;
    ll cursum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; cursum += i;
        modify(i, i);
    }
    for (int i = n; i >= 1; i--) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (query(mid) < x[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        l++; l = fin(l);
        ans[i] = l;
        modify(l, -l);
        un(l, l+1);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}