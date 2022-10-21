#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, INF = (int)1e9 + 50;

typedef pair<int, int> P;
int n;
int a[N];
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], a[i] -= (n - 1 - i);

    sort(a, a + n);
    int mn = INF;
    for(int i = n - 1; i >= 0; i--) {
        res[i] = a[i] + (n - 1 - i);
        if(i < n-1 && res[i] > res[i+1]) return cout << ":(\n", 0;
    }
    for(int i = 0; i < n; i++) cout << res[i] << " ";

}