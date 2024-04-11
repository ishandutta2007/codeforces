#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const int MAXP = (1 << 18) + 100;
const int P = (1 << 17);

int N, W;
pair <int, int> xv[MAXN];
int x[MAXN], v[MAXN];
pair <pair <ll, ll>, int> p[MAXN];
pair <pair <ll, ll>, int> p2[MAXN];

inline bool cmp(pair <pair <ll, ll>, int> left, pair <pair <ll, ll>, int> right)
{
    ll a = left.first.first, b = left.first.second;
    ll x = right.first.first, y = right.first.second;

    if (a * y == b * x)
        return left.second < right.second;
    return (a * y) < (b * x);
}
inline bool cmp2(pair <pair <ll, ll>, int> left, pair <pair <ll, ll>, int> right)
{
    ll a = left.first.first, b = left.first.second;
    ll x = right.first.first, y = right.first.second;

    return (a * y) < (b * x);
}

int o[MAXN];
int oloc[MAXN];
int o2[MAXN];

int seg[MAXP];
int seg_sum (int x)
{
    int ans = 0;
    x += P;
    while (x > 1)
    {
        if (x & 1)
            ans += seg[x-1];
        x /= 2;
    }
    return ans;
}

void upd (int x)
{
    x += P;
    while (x)
    {
        seg[x]++;
        x /= 2;
    }
}

int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> v[i];
        x[i] = -x[i];
        xv[i] = make_pair(x[i], v[i]);
    }
    sort (xv, xv + N);
    reverse (xv, xv + N);
    for (int i = 0; i < N; i++)
    {
        x[i] = xv[i].first;
        v[i] = xv[i].second;
    }

    for (int i = 0; i < N; i++)
    {
        p[i] = make_pair(make_pair(x[i], v[i]+W),i);
        p2[i] = make_pair(make_pair(x[i], v[i]-W),i);
        if (x[i] < 0)
        {
            p[i].first = make_pair(-p[i].first.first, -p[i].first.second);
            p2[i].first = make_pair(-p2[i].first.first, -p2[i].first.second);
        }
    }

    sort (p, p + N, cmp);
    sort (p2, p2 + N, cmp);

    for (int i = 0; i < N; i++)
    {
        o[i] = p[i].second;
        if (i > 0 && !cmp2(p[i-1], p[i]))
            oloc[o[i]] = oloc[o[i-1]];
        else
            oloc[o[i]] = i;
    }
    for (int i = 0; i < N; i++)
        o2[i] = p2[i].second;

    /*for (int i = 0; i < N; i++)
        cout << o[i] << " ";
    cout << "\n";
    for (int j = 0; j < N; j++)
        cout << o2[j] << " ";*/

    for (int i = 0; i < N; i++)
        seg[i] = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        int cc = i;
        while (cc < N - 1 && !cmp2(p2[cc], p2[cc+1]))
            cc++;
        vector <int> v;
        for (int j = i; j <= cc; j++)
            v.push_back(oloc[o2[j]]);
        sort(v.begin(), v.end());

        for (int j = 0; j < v.size(); j++)
            ans += i + j - seg_sum(v[j]);
        for (int j = 0; j < v.size(); j++)
            upd(v[j]);
        i = cc;
    }
    cout << ans << "\n";
}