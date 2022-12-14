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
        cin >> n >> m;
        cout << m / (n/2+1) << '\n';
    }
}