#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, a[N], f[N];
long long x, y, w;

void Enter() {
}

void Process() {
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x == y) { cout << "0 0\n"; continue; }
        if (x < y) swap(x, y);
        w = min(x % (x-y), (x-y) - x % (x-y));
        cout << x - y << ' ' << w << '\n';
    }
}