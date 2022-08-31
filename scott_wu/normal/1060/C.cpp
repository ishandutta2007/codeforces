#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N, M;
ll a[MAXN], b[MAXN];
ll arange[MAXN], brange[MAXN];
ll x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < M; i++)
        cin >> b[i];

    cin >> x;
    for (int i = 0; i < MAXN; i++)
        arange[i] = brange[i] = x + 1;

    for (int i = 0; i < N; i++)
    {
        ll csum = 0;
        for (int j = i; j < N; j++)
        {
            csum += a[j];
            arange[j-i+1] = min (arange[j-i+1], csum);
        }
    }
    for (int i = 0; i < M; i++)
    {
        ll csum = 0;
        for (int j = i; j < M; j++)
        {
            csum += b[j];
            brange[j-i+1] = min (brange[j-i+1], csum);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (arange[i] * brange[j] <= x)
                ans = max (ans, i * j);
        }
    cout << ans << "\n";
}