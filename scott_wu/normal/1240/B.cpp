#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 300100;

int Q;

int N;
int arr[MAXN];
int lo[MAXN], hi[MAXN];

void roll()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i <= N; i++)
    {
        lo[i] = MAXN;
        hi[i] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        lo[arr[i]] = min (lo[arr[i]], i);
        hi[arr[i]] = max (hi[arr[i]], i);
    }

    int ncnt = 0, nlo = -1e9;
    int ans = 0, ndiff = 0;
    for (int i = 1; i <= N; i++)
    {
        if (hi[i] == -1) continue;
        ndiff++;

        if (lo[i] > nlo)
        {
            ncnt++;
            nlo = hi[i];
        }
        else
        {
            ncnt = 1;
            nlo = hi[i];
        }
        ans = max (ans, ncnt);
    }

    cout << ndiff - ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> Q;
    for (int q = 0; q < Q; q++)
        roll();
}