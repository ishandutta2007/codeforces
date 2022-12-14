#include <iostream>
using namespace std;
int t, n;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cout << i+1 << ' ';
        cout << '\n';
    }
}