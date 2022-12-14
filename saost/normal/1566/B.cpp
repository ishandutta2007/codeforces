#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, m, res, a[N], f[N];
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> s;
        int dem = 0;
        for(int i=1; i<s.length(); ++i) if (s[i] != s[i-1]) dem += (s[i] - '0');
        dem += (1 - (s.back() - '0'));
        dem = min(dem, 2);
        cout << dem << '\n';
    }
}