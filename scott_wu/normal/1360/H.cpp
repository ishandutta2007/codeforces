#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
ll arr[110];

void gogo()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        ll res = 0;
        for (int j = 0; j < M; j++)
        {
            if (s[j] == '1')
                res += (1LL << (M - 1 - j));
        }
        arr[i] = res;
    }

    sort (arr, arr + N);

    ll ans = ((1LL << M) - N - 1) / 2;
    for (int i = 0; i < N; i++)
        if (arr[i] <= ans)
            ans++;

    for (int i = M - 1; i >= 0; i--)
        if (ans & (1LL << i))
            cout << 1;
        else
            cout << 0;
    cout << "\n";
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