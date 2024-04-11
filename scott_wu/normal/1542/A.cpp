#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    int N; cin >> N;

    int x = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        int p; cin >> p;
        x += (p % 2);
    }
    if (x == N) cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}