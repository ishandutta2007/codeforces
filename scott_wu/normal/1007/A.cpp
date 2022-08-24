#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);

    int cloc = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        while (cloc < N && arr[cloc] <= arr[i])
            cloc++;

        if (cloc < N && arr[cloc] > arr[i])
        {
            ans++;
            cloc++;
        }
    }
    cout << ans << "\n";
}