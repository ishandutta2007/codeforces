#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[300005];
    int b[300004];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i > 0) b[i - 1] = a[i] - a[i - 1];
    }
    sort(b, b + n - 1, greater<int>());
    int ans = a[n - 1] - a[0];
    for(int i = 0; i < k - 1; i++) ans -= b[i];
    cout << ans << endl;
}