#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int arr[1100];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);

    int ans = 1e9;
    for (int i = 0; i + 1 < N; i++)
        ans = min (ans, arr[i+1] - arr[i]);
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