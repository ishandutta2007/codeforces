#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    ll n, m, x, y, k;
    cin >> n >> m >> k >> x >> y;
    --x;
    --y;
    if (n == 1)
    {
        cout << k / m + bool(k % m) << " ";
        cout << k / m << " ";
        cout << k / m + (k % m > y) << endl;
        return 0;
    }
    ll periods = ((k / m) / (n - 1)) / 2;
    k %= m * (n - 1) * 2;
    ll arr[100][100];
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            arr[i][j] = 0;
    for (int i = 0; i < m; ++i)
    {
        arr[0][i] = periods;
        arr[n - 1][i] = periods;
    }
    for (int i = 1; i < n - 1; ++i)
        for (int j = 0; j < m; ++j)
            arr[i][j] += periods * 2;
    int cnt = 0;
    for (int i = 0; i < n - 1 && cnt < k; ++i)
        for (int j = 0; j < m && cnt < k; ++j)
        {
            arr[i][j] += 1;
            cnt++;
        }
    for (int i = n - 1; i > 0 && cnt < k; --i)
        for (int j = 0; j < m && cnt < k; ++j)
        {
            arr[i][j] += 1;
            cnt++;
        }
    ll mx = arr[0][0], mn = arr[0][0];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] > mx)
                mx = arr[i][j];
            if (arr[i][j] < mn)
                mn = arr[i][j];
        }
    cout << mx << " " << mn << " " << arr[x][y] << endl;
}