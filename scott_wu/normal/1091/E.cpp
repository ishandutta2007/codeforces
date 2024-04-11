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
const int MAXN = 500100;

int N;
int deg[MAXN];
ll ps[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> deg[i];
    sort (deg, deg + N);
    reverse (deg, deg + N);

    ps[0] = 0;
    for (int i = 0; i < N; i++)
        ps[i+1] = ps[i] + deg[i];

    int cloc = N;
    ll csum = 0;
    ll lo = 0, hi = N;
    for (int i = 1; i <= N; i++)
    {
        while (cloc < i)
        {
            csum -= deg[cloc];
            cloc++;
        }
        while (cloc > i && deg[cloc-1] <= i)
        {
            csum += deg[cloc-1];
            cloc--;
        }
        ll vscore = i + i * ((ll) i - 1) - ps[i] + csum + i * ((ll) cloc - i);
        //cout << i << " " << vscore << "\n";
        lo = max (lo, i - vscore);
        hi = min (hi, cloc + vscore);
    }

    vector <int> ans;
    int r = ps[N] % 2;
    while (r <= N)
    {
        if (r >= lo && r <= hi)
            ans.push_back(r);
        r += 2;
    }

    if (!ans.size()) ans.push_back(-1);

    for (int i = 0; i < ans.size(); i++)
    {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}