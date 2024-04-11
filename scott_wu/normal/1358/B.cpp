#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        vector <int> v;
        for (int i = 0; i < N; i++)
        {
            int x; cin >> x;
            v.push_back(x);
        }
        v.push_back(0);
        sort(v.begin(), v.end());

        int ans = 0;
        for (int i = 0; i <= N; i++)
            if (v[i] <= i)
                ans = i + 1;
        cout << ans << "\n";
    }
}