#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[300005];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n, greater<ll>());
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int q;
        cin >> q;
        cout << sum - a[q - 1] << endl;
    }
}