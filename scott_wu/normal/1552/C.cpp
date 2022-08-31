#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 420;

int N, K;
int arr[MAXN];
int ps[MAXN];
pair <int, int> pb[MAXN];

void gogo()
{
    for (int i = 0; i < MAXN; i++)
        arr[i] = ps[i] = 0;

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> pb[i].first >> pb[i].second;
        pb[i].first--;
        pb[i].second--;

        arr[pb[i].first] = 1;
        arr[pb[i].second] = 1;

        if (pb[i].first > pb[i].second) swap (pb[i].first, pb[i].second);
    }

    for (int i = 0; i <= 2 * N; i++)
        ps[i+1] = ps[i] + (1 - arr[i]);

    int nleft = (N - K);
    int res = (nleft * (nleft - 1)) / 2;
    for (int i = 0; i < K; i++)
        for (int j = i + 1; j < K; j++)
        {
            if (min (pb[i].second, pb[j].second) > max (pb[i].first, pb[j].first))
            {
                if ((pb[i].first<pb[j].first) == (pb[i].second<pb[j].second))
                    res++;
            }
        }
    for (int i = 0; i < K; i++)
    {
        int np = ps[pb[i].second] - ps[pb[i].first];
        np = min (np, 2 * nleft - np);
        res += np;
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}