#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr)

#define int long long
const int MOD = 1e9 + 7;


vector <int> pows;
vector <int> a;
int n;
int q;

int maxN = 1;
const int INF = 0;

vector <int> tree;


void build()
{
    int n = a.size();
    while (maxN < n)
    {
        maxN *= 2;
    }
    tree.assign(maxN * 2, INF);

    for (int i = 0; i < n; i++)
    {
        tree[i + maxN] = a[i];
    }

    for (int i = maxN - 1; i > 0; i--)
    {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    return;
}

int get(int val, int tl, int tr, int l, int r)
{
    if (l > tr || tl > r)
    {
        return INF;
    }
    if (l <= tl && tr <= r)
    {
        return tree[val];
    }
    int tm = (tl + tr) / 2;
    int a = get(val * 2, tl, tm, l, r);
    int b = get(val * 2 + 1, tm + 1, tr, l, r);
    return a + b;
}

void read()
{
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        a[i] = 1;
        if (x == '0')
            a[i] = 0;
    }
    build();
}

int res(int sum, int len)
{
    if (sum == 0)
        return 0;
    int ans = 0;
    if (len - sum > 0)
      ans += ((pows[len - sum] - 1) * (pows[sum] - 1)) % MOD;
    ans += pows[sum] - 1;
    ans %= MOD;
    return ans;
}

int ans = 0;
vector <int> f;
void run()
{
    pows.resize(n + 10, 1);
    for (int i = 1; i < n + 10; i++)
    {
        pows[i] = pows[i - 1] * 2;
        pows[i] %= MOD;
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int s = get(1, 0, maxN - 1, l, r);
        ans = res(s, r - l + 1);
        ans %= MOD;
        f.push_back(ans);
    }
}

void write()
{
    for (auto i : f)
        cout << i % MOD << endl;
}

signed main()
{
    FAST;
        read();
        run();
        write();
    return 0;
}