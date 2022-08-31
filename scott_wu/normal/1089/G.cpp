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
const int MAXN = 100100;

void gogo()
{
    int N; cin >> N;
    int arr[14];
    int ntot = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
        arr[i+7] = arr[i];
        ntot += arr[i];
    }

    int ans = 1e9;
    for (int i = 0; i < 7; i++)
    {
        int cc = 0;
        for (int j = 0; j <= 7; j++)
        {
            ans = min (ans, 7 * max (0, (N - cc - 1) / ntot + 1) + j);
            if (cc >= N)
                ans = min (ans, j);
            cc += arr[i+j];
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int ntest; cin >> ntest;
    for (int test = 0; test < ntest; test++)
        gogo();
}