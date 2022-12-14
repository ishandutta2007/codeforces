#include <iostream>

using namespace std;
long long t, r, b, d;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> r >> b >> d; ++d;
        if (r*d<b || b*d<r) cout << "NO\n";
        else cout << "YES\n";
    }
}