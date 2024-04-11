#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = (1 << 16) + 100;

int N, K;
pair <int, int> res[MAXN];

void gogo()
{
    cin >> N >> K;
    if (N == 4 && K == 3)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < N / 2; i++)
    {
        res[i] = make_pair (i, N - 1 - i);
    }

    int zloc = 0;
    for (int i = 0; (1 << i) < N; i++)
    {
        if (K & (1 << i))
        {
            if ((1<<i) * 2 == N)
                swap (res[zloc].first, res[N/2-1].second);
            else
            {
                swap (res[zloc].first, res[(1<<i)].first);
                zloc = (1<<i);
            }
        }
    }

    for (int i = 0; i < N / 2; i++)
        cout << res[i].first << " " << res[i].second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}