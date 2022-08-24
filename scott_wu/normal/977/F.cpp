#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
pair <int, int> val[MAXN];
int seg[MAXN];

int findp (pair <int, int> c)
{
    int lo = 0, hi = N - 1;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (val[mid] < c)
            lo = mid;
        else
            hi = mid - 1;
    }
    if (val[lo].first == c.first && val[lo].second < c.second)
        return seg[lo] + 1;
    return 1;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> val[i].first;
        val[i].second = i;
    }
    sort (val, val + N);

    for (int i = 0; i < N; i++)
    {
        seg[i] = findp(make_pair(val[i].first - 1, val[i].second));
    }

    int cm = 0;
    for (int i = 0; i < N; i++)
        cm = max (cm, seg[i]);
    int chi = -1, cs = 0;
    vector <int> v;

    cout << cm << "\n";
    for (int i = N - 1; i >= 0; i--)
    {
        if (seg[i] == cm && (chi == -1 || (val[i].first == chi && val[i].second < cs)))
        {
            chi = val[i].first - 1;
            cs = val[i].second;
            cm--;
            v.push_back(val[i].second + 1);
        }
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}