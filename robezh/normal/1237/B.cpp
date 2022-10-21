#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n;
int a[N];
int idx[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        idx[b] = i;
    }
    int mx = 0, res = 0;
    for(int i = 1; i <= n; i++) {
        if(mx > idx[a[i]]) res++;
        mx = max(mx, idx[a[i]]);
    }
    cout << res << "\n";
}