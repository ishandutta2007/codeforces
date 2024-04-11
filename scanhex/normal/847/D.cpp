#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long nagai;

struct nd
{
    nd* le;
    nd* ri;
    nagai mx;
    nagai psh;
    nd()
            : mx(0), psh(0), le(nullptr), ri(nullptr)
    {}
    void children()
    {
        if (!le)
            le = new nd();
        if (!ri)
            ri = new nd();
    }
    void push()
    {
        children();
        le->mx += psh;
        le->psh += psh;
        ri->mx += psh;
        ri->psh += psh;
        psh = 0;
    }
    void add(int l, int r, int ql, int qr, nagai val)
    {
        if (l >= qr || ql >= r)
            return;
        if (ql <= l && r <= qr)
        {
            psh += val;
            mx += val;
            return;
        }
        push();
        int m = (l + r) / 2;
        le->add(l, m, ql, qr, val);
        ri->add(m, r, ql, qr, val);
        mx = max(le->mx, ri->mx);
    }
    nagai get(int l, int r, int ql, int qr)
    {
        if (l >= qr || ql >= r)
            return -2e9;
        if (ql <= l && r <= qr)
            return mx;
        push();
        int m = (l + r) / 2;
        return max(le->get(l, m, ql, qr), ri->get(m, r, ql, qr));
    }
};

int MX = 1e6;

int main()
{
    int n, T;
    cin >> n >> T;
    vector<nagai> t(n);
    for (auto& x : t)
        cin >> x;
    ++n;
    t.insert(t.begin(), 0);
    vector<nagai> t1(n);
    for (int i = 0; i < n; ++i)
        t1[i] = t[i] - i;
    vector<nagai> ts;
    t1[0] = -n - 1;
    for (nagai x : t1)
        ts.push_back(x);
    sort(ts.begin(), ts.end());
    ts.resize(unique(ts.begin(), ts.end()) - ts.begin());
    for (nagai& x : t1)
        x = lower_bound(ts.begin(), ts.end(), x) - ts.begin();
    auto rt = new nd;
    for (int i = 0; i < n; ++i)
    {
        if (t[i] >= T || i >= T)
            continue;
        nagai dp = rt->get(0, MX, 0, t1[i] + 1) + 1;
        if (i == 0)
            dp = 1;
        nagai mem = rt->get(0, MX, t1[i], t1[i] + 1);
        if (dp > mem)
            rt->add(0, MX, t1[i], t1[i] + 1, dp - mem);
        rt->add(0, MX, t1[i] + 1, lower_bound(ts.begin(), ts.end(), T - i) - ts.begin(), 1);
    }
    cout << rt->get(0, MX, 0, MX) - 1 << endl;
    return 0;
}