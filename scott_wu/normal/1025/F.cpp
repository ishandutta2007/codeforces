#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 2100;

int N;
ll x[MAXN], y[MAXN];
ll tot;

vector <pair <ll, ll> > v;

long long cross(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first * b.second - b.first * a.second;
}

inline bool cmp (pair <ll, ll> left, pair <ll, ll> right)
{
    static pair<ll, ll> zero(0, 0);

    if (make_pair(left.second, left.first) > zero ^ make_pair(right.second, right.first) > zero)
        return make_pair(left.second, left.first) > zero;

    return cross(left, right) > 0;
}

void run (int cloc)
{
    v.clear();
    for (int i = 0; i < N; i++)
        if (i != cloc)
            v.push_back(make_pair(x[i] - x[cloc], y[i] - y[cloc]));

    sort (v.begin(), v.end(), cmp);
    /*cout << "SORTED " << cloc << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    cout << "\n\n";*/
    int vv = v.size();
    for (int i = 0; i < vv; i++)
        v.push_back(v[i]);

    int cend = 0;
    for (int i = 0; i < vv; i++)
    {
        cend = max (cend, i + 1);
        while (cend < i + vv && cross (v[i], v[cend]) > 0)
            cend++;

        ll l = cend - i - 1;
        ll r = N - 2 - l;
        tot += (l * (l - 1) * r * (r - 1)) / 4;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];

    tot = 0;
    for (int i = 0; i < N; i++)
        run (i);
    cout << tot / 2 << "\n";
}