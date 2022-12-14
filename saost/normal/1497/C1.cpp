#include <iostream>
#include <algorithm>
using namespace std;
int t, n, k;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n&1) cout << n/2 << ' ' << n/2 << ' ' << 1 << '\n';
        else {
            if (n%4==0) cout << n/2 << ' ' << n/4 << ' ' << n/4 << '\n';
            else cout << n/2-1 << ' ' << n/2-1 << ' ' << n-n/2*2+2 << '\n';
        }
    }
}