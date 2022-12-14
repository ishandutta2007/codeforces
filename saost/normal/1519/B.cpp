#include <iostream>

using namespace std;
long long t, n, m, k;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        if (m*n == k+1) cout << "YES\n"; else cout << "NO\n";
    }
}