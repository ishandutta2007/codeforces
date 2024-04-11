#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int prev = -1e9;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] <= prev)
            arr[i]++;
        if (arr[i] > prev)
        {
            prev = arr[i];
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}