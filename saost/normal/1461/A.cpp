#include <iostream>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        FOR(i, 1, k) cout << 'a';
        FOR(i, 1, n - k) cout << (char) (i % 3 + 'a');
        cout << '\n';
    }
}