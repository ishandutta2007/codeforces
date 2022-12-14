#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100005;
int t, n, b, d;
long double a, c;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        while (a > 1) ++b, a/=10;
        while (c > 1) ++d, c/=10;
        if (a == c && b == d) cout << "=\n";
        else if (b < d || b == d && a < c) cout << "<\n";
        else cout << ">\n";
    }
}