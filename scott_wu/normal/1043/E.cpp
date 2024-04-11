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

int N, M;
pair <pair <int, int>, int> pp[MAXN];
ll psl[MAXN], psr[MAXN];
pair <int, int> pbad[MAXN];
ll ans[MAXN];

inline bool cmp (pair <pair <int, int>, int> left, pair <pair <int, int>, int> right)
{
    return left.first.first - left.first.second < right.first.first - right.first.second;
}

inline bool cmp2 (pair <pair <int, int>, int> left, pair <pair <int, int>, int> right)
{
    return left.second < right.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> pp[i].first.first >> pp[i].first.second;
        pp[i].second = i;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> pbad[i].first >> pbad[i].second;
        pbad[i].first--;
        pbad[i].second--;
    }

    sort (pp, pp + N, cmp);
    for (int i = 0; i < N; i++)
    {
        psl[i+1] = psl[i] + pp[i].first.first;
        psr[i+1] = psr[i] + pp[i].first.second;
    }

    for (int i = 0; i < N; i++)
    {
        ll v = i * (ll) pp[i].first.second + (N - 1 - i) * (ll) pp[i].first.first;
        v += psl[i];
        v += psr[N] - psr[i+1];
        ans[pp[i].second] = v;
    }

    sort (pp, pp + N, cmp2);
    for (int i = 0; i < M; i++)
    {
        int l = pbad[i].first, r = pbad[i].second;
        ll x1 = pp[l].first.first, y1 = pp[l].first.second;
        ll x2 = pp[r].first.first, y2 = pp[r].first.second;
        ll ct = min (x1 + y2, x2 + y1);
        ans[l] -= ct;
        ans[r] -= ct;
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}