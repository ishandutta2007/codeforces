#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 510;

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;

    int ans = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 2 * N; i++)
    {
        int cloc = -1;
        for (int j = 0; j < i; j++)
            if (arr[j] == arr[i])
                cloc = j;

        if (cloc == -1)
            continue;
        int nadd = i - cloc - 1;
        ans += nadd;
        for (int j = 0; j < nadd; j++)
            swap (arr[i-j], arr[i-j-1]);
    }
    cout << ans << "\n";
}