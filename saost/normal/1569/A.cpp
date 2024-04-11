#include <iostream>
using namespace std;
int t, n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int i=0;
        for(; i+1<n; ++i) if (s[i] != s[i+1]) {
            cout << i+1 << ' ' << i+2 << '\n';
            break;
        }
        if (i+1 == n) cout << -1 << ' ' << -1 << '\n';
    }
}