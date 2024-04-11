#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, M;
int aloc[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int T = 0;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
        {
            int x; cin >> x;
            aloc[x] = i;
        }

        int chi = -1;
        ll ans = 0;
        for (int i = 0; i < M; i++)
        {
            int x;
            cin >> x;
            x = aloc[x];
            if (x > chi)
            {
                ans += 2 * (x - i) + 1;
                chi = x;
            }
            else
                ans++;
        }
        cout << ans << "\n";
    }
}