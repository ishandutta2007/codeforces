#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, Q;
ll arr[MAXN];
map <pair <int, int>, int> mm;
ll ans;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        ans += arr[i];
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        z--;
        if (mm.find(make_pair (x, y)) != mm.end())
        {
            int zv = mm[make_pair(x, y)];
            arr[zv]++;
            mm.erase(make_pair(x, y));
            if (arr[zv] > 0) ans++;
        }
        if (z >= 0)
        {
            mm[make_pair(x, y)] = z;
            arr[z]--;
            if (arr[z] >= 0) ans--;
        }

        cout << ans << "\n";
    }
}