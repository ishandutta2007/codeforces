#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 200179;

int n;
vector < int > e[N];
ll ct, co;

ipair dfs(int v, int p = -1)
{
    if (e[v].empty())
        return ipair(0, 0);
    int ans = 0, ansT = 0;
    vector < ipair > d;
    for (int nv : e[v])
    {
        if (nv == p)
            continue;
        d.push_back(dfs(nv, v));
        ansT += d.back().first;
    }
    ansT += sz(d);
    int mx1 = -IINF, mx2 = -IINF;
    for (auto nv : d)
    {
        int q = nv.first - nv.second;
        if (q >= mx1)
        {
            mx2 = mx1;
            mx1 = q;
        } else if (q >= mx2)
            mx2 = q;
    }
    ans = ansT;
    ansT = min(ansT, ansT - 1 - mx1);
    if (sz(d) > 1)
        ans = min(ans, ans - 2 - mx1 - mx2);
    ans = min(ans, ansT);
    return ipair(ans, ansT);
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> ct >> co;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    if (ct >= co)
    {
        int ccnt = 0;
        for (int i = 0; i < n; ++i)
            if (sz(e[i]) == 1)
                ++ccnt;
        if (ccnt >= n - 1)
            cout << co * (n - 2) + ct << "\n";
        else
            cout << co * (n - 1) << "\n";
    } else {
        int vk = dfs(0).first;
        cout << ct * (n - 1 - vk) + co * vk << "\n";
    }

    return 0;
}