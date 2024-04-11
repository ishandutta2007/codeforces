#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const double EPS = 1e-10;

int n, k;
double h;
pair <ll, pair <ll, int> > lem[MAXN];
int ans[MAXN];

bool solve (double t)
{
    int count = k;
    for (int i = n - 1; i >= 0; i--)
        if (h * count / lem[i].second.first <= t)
        {
            ans[count-1] = i;
            count--;
            if (count <= 0) break;
        }
    return !(count > 0);
}

int main()
{
    cin >> n >> k >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> lem[i].first;
        lem[i].second.second = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> lem[i].second.first;
    }
    sort (lem, lem + n);
    double lo = 0, hi = 1.5e9;
    for (int i = 0; i < 120; i++)
    {
        double mid = (lo + hi) / 2;
        if (solve (mid))
            hi = mid;
        else
            lo = mid;
    }
    solve (hi);
    for (int i = 0; i < k; i++)
    {
        cout << lem[ans[i]].second.second + 1;
        if (i < k - 1)
            cout << " ";
    }
    cout << "\n";
    //system ("Pause");
    return 0;
}