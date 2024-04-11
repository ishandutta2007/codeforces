#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int arr[1001];

int main()
{
    cout << fixed << setprecision(5);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort (arr, arr + n);
    double ans = max (arr[0], l - arr[n-1]);
    for (int i = 0; i < n - 1; i++)
    ans = max (ans, (arr[i+1] - arr[i]) / 2.);
    cout << ans << "\n";
    return 0;
}