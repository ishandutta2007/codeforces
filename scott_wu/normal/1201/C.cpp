#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll K;
int arr[MAXN];

bool works (ll x)
{
    ll ctot = 0;
    for (int i = N / 2; i < N; i++)
        ctot += max (0LL, x - arr[i]);
    return ctot <= K;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);

    ll lo = 0, hi = 2e9;
    while (lo < hi)
    {
        ll mid = (lo + hi + 1) / 2;
        if (works (mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo << "\n";
}