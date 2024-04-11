#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N;
char c[MAXN];
char nc[MAXN];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
        nc[i] = c[i];
    }
    sort (nc, nc + N);

    int ans = 0;
    for (int i = 0; i < N; i++)
        if (c[i] != nc[i]) ans++;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}