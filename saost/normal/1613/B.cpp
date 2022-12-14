#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 200005;
int t, n, b, d, a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        sort(a+1, a+n+1);
        for(int i=1; i*2<=n; ++i) cout << a[i + 1] << ' ' << a[1] << '\n';
    }
}