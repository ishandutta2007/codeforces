#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int t, n, a[200005];
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        if (a[1] != n && a[n] != n) cout << -1 << '\n';
        else {
            if (a[1] == n) {
                cout << a[1] << ' ';
                for(int i=n; i>1; --i) cout << a[i] << ' ';
                cout << '\n';
            }
            else {
                cout << a[n] << ' ';
                for(int i=n-1; i; --i) cout << a[i] << ' ';
                cout << '\n';
            }
        }
    }
}