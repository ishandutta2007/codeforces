#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, m;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> m;
        cout << (a+b+c-3 >= m && max(max(a,b),c) * 2 - (a+b+c) - 1 <= m ? "YES\n" : "NO\n");
    }
}