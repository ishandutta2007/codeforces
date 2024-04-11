#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, S;
ll arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);

    int mloc = (N / 2);
    ll res = 0;
    for (int i = 0; i < N; i++)
    {
        if (i <= mloc && arr[i] > S)
            res += arr[i] - S;
        if (i >= mloc && arr[i] < S)
            res += S - arr[i];
    }
    cout << res << "\n";
}