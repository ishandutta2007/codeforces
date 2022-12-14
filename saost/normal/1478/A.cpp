#include <iostream>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
using namespace std;
int t, n, a[205];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> a[1];
        int sl = 1, res = 1;
        FOR(i, 2, n) {
            cin >> a[i];
            if (a[i] == a[i-1]) sl++;
            else {
                res = max(res, sl);
                sl = 1;
            }
        }
        res = max(res, sl);
        cout << res << '\n';
    }
}