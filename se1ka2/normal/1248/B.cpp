#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[100002];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll t = 0, y = 0;
    for(int i = 0; i < n / 2; i++) y += a[i];
    for(int i = n / 2; i < n; i++) t += a[i];
    cout << t * t + y * y << endl;
}