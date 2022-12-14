#include <iostream>
using namespace std;
const int N = 100005;
int t, n, m, a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        n = abs(n - m);
        cout << n/5 + (n%5+1)/2 << '\n';
    }
}