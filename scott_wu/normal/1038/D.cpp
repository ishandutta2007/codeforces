#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;

int N;
int arr[500100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    if (N == 1)
    {
        cout << arr[0] << "\n";
        return 0;
    }
    sort (arr, arr + N);
    ll res = arr[N-1] - arr[0];
    for (int i = 1; i < N - 1; i++)
        res += max (arr[i], -arr[i]);
    cout << res << "\n";
}