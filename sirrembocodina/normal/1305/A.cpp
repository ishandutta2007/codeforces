#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)


using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    forn (q, t) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        forn (i, n) {
            cin >> a[i];
        }
        forn (i, n) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        forn (i, n) {
            cout << a[i] << " ";
        }
        cout << endl;
        forn (i, n) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}