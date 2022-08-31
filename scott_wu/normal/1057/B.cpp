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

int N;
int arr[5100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int cs = 0;
        for (int j = i; j < N; j++)
        {
            cs += arr[j];
            if (cs > 100 * (j - i + 1))
                ans = max (ans, j - i + 1);
        }
    }
    cout << ans << "\n";
}