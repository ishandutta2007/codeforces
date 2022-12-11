#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;

int main()
{
    //freopen("a.in", "r", stdin);
    int n, a, b, c, ans = 0;
    cin >> b >> a >> c >> n;
    while (n--) {
        int x;
        cin >> x;
        if (a < x && x < c) ans++;
    }
    cout << ans;
    return 0;
}