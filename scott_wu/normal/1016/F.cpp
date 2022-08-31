#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N, Q;
vector <pair <int, int> > edge[MAXN];
ll ndist[MAXN];

ll adist[MAXN], bdist[MAXN];
pair <pair <ll, ll>, int> vv[MAXN];
set <ll> elist;
set <pair <ll, int> > ss;

bool cmp2 (pair <ll, ll> left, pair <ll, ll> right)
{
    return left.first - left.second < right.first - right.second;
}

bool cmp (pair <pair <ll, ll>, int> left, pair <pair <ll, ll>, int> right)
{
    return cmp2 (left.first, right.first);
}

void flood (int cloc, ll cdist)
{
    if (ndist[cloc] != -1) return;
    ndist[cloc] = cdist;
    for (auto e : edge[cloc])
        flood (e.first, cdist + e.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        edge[a].push_back(make_pair(b, d));
        edge[b].push_back(make_pair(a, d));
        elist.insert(N*a+b);
        elist.insert(N*b+a);
    }

    for (int i = 0; i < N; i++)
        ndist[i] = -1;
    flood (0, 0);
    for (int i = 0; i < N; i++)
    {
        adist[i] = ndist[i];
        ndist[i] = -1;
    }
    flood (N - 1, 0);
    for (int i = 0; i < N; i++)
    {
        bdist[i] = ndist[i];
        vv[i] = make_pair (make_pair (adist[i], bdist[i]), i);
    }

    sort (vv, vv + N, cmp);

    ll mres = 0;
    for (int i = 0; i < N; i++)
    {
        for (auto it = ss.begin(); it != ss.end(); it++)
        {
            if (elist.find(N*(*it).second + vv[i].second) != elist.end())
                continue;
            mres = max (mres, vv[i].first.second - (*it).first);
            break;
        }
        ss.insert(make_pair (-vv[i].first.first, vv[i].second));
    }

    for (int i = 0; i < Q; i++)
    {
        ll x; cin >> x;
        printf("%lld\n", min (mres + x, adist[N-1]));
    }
}