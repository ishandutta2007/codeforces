#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int
main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector < int > type(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> type[i];
    }
    ll ans = 0LL;
    ll curLeft = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (type[i] == 0) {
            ++curLeft;
        } else {
            ans += curLeft;
        }
    }
    /*ll curRight = 0;
    for (int i = 0; i < n; ++i) {
        if (type[i] == 1) {
            ++curRight;
        } else {
            ans += curRight;
        }
    }*/
    cout << ans << '\n';
    return 0;
}