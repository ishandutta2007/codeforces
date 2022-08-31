#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, V;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> V;
    int ans = 0;
    vector <int> v;
    for (int i = 0; i < N; i++)
    {
        int k; cin >> k;
        int mm = 1e9;
        for (int j = 0; j < k; j++)
        {
            int x; cin >> x;
            mm = min (mm, x);
        }
        if (mm < V)
            {
                ans++;
                v.push_back(i+1);
            }
    }
    cout << ans << "\n";
    for (int i = 0; i < ans; i++)
    {
        if (i) cout << " ";
        cout << v[i];
    }
}