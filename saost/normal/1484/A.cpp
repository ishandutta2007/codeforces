#include <iostream>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
using namespace std;
const int N = 1e5 + 5;
int t, n, m, a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << n*m << '\n';
    }
}