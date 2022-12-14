#include <iostream>
#include <algorithm>
using namespace std;
int t, n, a[100005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+n+1);
        for(int i=1; i<=n; i++) {
            if (i==1 || a[i] != a[i-1]) cout << a[i] << ' ';
        }
        for(int i=2; i<=n; i++) {
            if (a[i] == a[i-1]) cout << a[i] << ' ';
        }
        cout << '\n';
    }
}