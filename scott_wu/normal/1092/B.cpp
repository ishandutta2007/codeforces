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
int arr[110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);

    int ans = 0;
    for (int i = 0; i < N; i += 2)
        ans += arr[i+1] - arr[i];
    cout << ans << "\n";
}