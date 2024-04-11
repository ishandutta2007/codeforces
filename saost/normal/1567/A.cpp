#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for(int i=0; i<n; ++i) {
            if (s[i] == 'U') cout << 'D';
            else if (s[i] == 'D') cout << 'U';
            else cout << s[i];
        }
        cout << '\n';
    }
}