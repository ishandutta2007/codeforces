#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if ((a + b + c) % 3 == 0) cout << "0\n"; else cout << "1\n";
    }
}