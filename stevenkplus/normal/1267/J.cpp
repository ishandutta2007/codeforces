#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2000100;

int N;
int nc[MAXN];
vector <int> v;

int roll (int x)
{
    int ans = 0;
    for (int k : v)
    {
        int nv = (k - 1) / x + 1;
        if (nv * (x - 1) > k)
            return 1e9;
        ans += nv;
    }
    return ans;
}

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        nc[i] = 0;

    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        nc[x-1]++;
    }

    v.clear();
    for (int i = 0; i < N; i++)
        if (nc[i])
            v.push_back(nc[i]);
    sort(v.begin(), v.end());

    int mv = v[0];
    int ans = 1e9;
    for (int i = 1; i <= mv + 1; i++)
        ans = min (ans, roll (i));

    cout << ans << "\n";
}

int T;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}