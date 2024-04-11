#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, K;
int flo[MAXN], fhi[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        flo[i] = 1e9;
        fhi[i] = -1e9;
    }
    for (int i = 0; i < K; i++)
    {
        int x; cin >> x;
        x--;
        flo[x] = min (flo[x], i);
        fhi[x] = max (fhi[x], i);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i - 1; j <= i + 1; j++)
        {
            if (j < 0 || j >= N) continue;
            if (flo[i] > fhi[j])
                ans++;
        }
    }
    cout << ans << "\n";
}