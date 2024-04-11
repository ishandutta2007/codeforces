#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, INF = (int)1e9 + 50;
typedef long long ll;

int n;
int a[N];
ll res = 0;
int mx = INF;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n - 1; i >= 0; i--) {
        if(mx > 0) mx--;
        mx = min(a[i], mx);
        res += mx;
    }
    cout << res << endl;

}