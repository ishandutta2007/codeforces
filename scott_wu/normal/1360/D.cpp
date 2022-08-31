#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    int N, K;
    cin >> N >> K;

    int ans = N;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            int a = i, b = N / i;
            if (a <= K)
                ans = min (ans, b);
            if (b <= K)
                ans = min (ans, a);
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        gogo();
    }
}