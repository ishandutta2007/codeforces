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

int N, M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    ll ans = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
        {
            if ((i * i + j * j) % M == 0)
            {
                if (i <= N && j <= N)
                {
                    ll nleft = (N - i) / M + 1;
                    ll nright = (N - j) / M + 1;
                    if (i == 0) nleft--;
                    if (j == 0) nright--;
                    ans += nleft * nright;
                }
            }
        }
    cout << ans << "\n";
}