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
const int MAXN = 1100;

int N, R;
int h[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> R;
    for (int i = 0; i < N; i++)
        cin >> h[i];
    R--;

    int cloc = 0, ans = 0;
    while (cloc < N)
    {
        bool found = false;
        for (int i = cloc + R; i >= cloc - R; i--)
        {
            if (i >= 0 && i < N && h[i])
            {
                found = true;
                cloc = i + R + 1;
                ans++;
                break;
            }
        }
        if (!found)
        {
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans << "\n";
}