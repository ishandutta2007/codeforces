#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2000100;
int N, M;
int arr[MAXN];
int hi[MAXN];
string s;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    arr[0] = 0;
    for (int i = 1 ; i <= N; i++)
        cin >> arr[i];
    arr[N+1] = M;
    N += 2;

    hi[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        hi[i] = hi[i+1];
        if (i % 2 == 0)
            hi[i] += (arr[i+1] - arr[i]);
    }

    ll res = hi[0];
    ll ctot = 0;
    for (int i = 0; i + 1 < N; i++)
    {
        res = max (res, ctot + (arr[i+1] - arr[i]) - 1 + (M - arr[i+1] - hi[i+1]));

        if (i % 2 == 0)
        {
            ctot += (arr[i+1] - arr[i]);
        }
    }
    cout << res << "\n";
}