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

int N;
int arr[110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N / 2; i++)
        cin >> arr[i];
    sort (arr, arr + N / 2);
    
    int res = 0, res2 = 0;
    for (int i = 0; i < N / 2; i++)
    {
        res += abs (2 * i + 1 - arr[i]);
        res2 += abs (2 * i + 2 - arr[i]);
    }
    cout << min (res, res2) << "\n";
}