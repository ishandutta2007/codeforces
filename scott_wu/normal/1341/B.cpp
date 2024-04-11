#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, K;
int arr[MAXN];
int ps[MAXN];

void gogo()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    ps[0] = 0;
    for (int i = 1; i < N - 1; i++)
    {
        ps[i] = ps[i-1];
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1])
            ps[i]++;
    }

    int bloc = 0, bans = -1;
    for (int i = 0; i + K <= N; i++)
        if (ps[i+K-2] - ps[i] > bans)
        {
            bans = ps[i+K-2] - ps[i];
            bloc = i;
        }
    cout << bans + 1 << " " << bloc + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}