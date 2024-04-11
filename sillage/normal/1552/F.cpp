#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
const long long mod = 998244353;
map<int, int> mp;
long long  q[maxn], s[maxn];
int top, cnt, n,  l[maxn], r[maxn];
long long tr[maxn], len[maxn], ans;

void ad(int x, long long val) {
    for (; x <= cnt + 10; x += x & -x) (tr[x] += val) %= mod;
}
long long get(int x) {
    long long ret = 0;
    for (; x; x -= x & -x) (ret += tr[x]) %= mod;
    return ret;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i] >> l[i] >> s[i];
        q[++top] = l[i];
        q[++top] = r[i];
        len[i] = r[i] - l[i];
    }
    ans = r[n] + 1;
    sort(q + 1, q + top + 1);
    for (int i = 1; i <= top; i++) if (!mp[q[i]]) mp[q[i]] = ++cnt;
    for (int i = 1; i <= n; i++) l[i] = mp[l[i]], r[i] = mp[r[i]];
    for (int i = n; i >= 1; i--)
    {
        s[i] += get(r[i]);
        (ans += s[i] * len[i]) %= mod;
        ad(l[i], s[i]);
        ad(r[i] + 1, -s[i]);
    }
    cout << ans << endl;
}