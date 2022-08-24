#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, X;
int arr[110000];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> X;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);


    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += max (1, X - i) * (ll) arr[i];
    }
    cout << ans << "\n";
}