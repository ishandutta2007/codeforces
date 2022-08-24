#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];
int floc[MAXN];
int lloc[MAXN];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i <= N; i++)
    {
        floc[i] = 1e9;
        lloc[i] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        floc[arr[i]] = min (floc[arr[i]], i);
        lloc[arr[i]] = max (lloc[arr[i]], i);
    }

    int plast = -1;
    int pbest = -1;
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (i > plast && lloc[arr[i]] != i)
        {
            res += lloc[arr[i]] - i - 1;
            plast = lloc[arr[i]];
        }
        else if (lloc[arr[i]] != i)
        {
            pbest = max (pbest, lloc[arr[i]]);
        }

        if (i == plast && pbest > i)
        {
            res += pbest - plast - 1;
            plast = pbest;
        }
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T = 1;
    for (int t = 0; t < T; t++)
        gogo();
}