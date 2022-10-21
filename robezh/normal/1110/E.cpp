#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n;
int a[2][N];
vector<int> d[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < n; i++) cin >> a[k][i];
        for(int i = 1; i < n; i++) d[k].push_back(a[k][i] - a[k][i-1]);
        sort(d[k].begin(), d[k].end());
    }
    if(a[0][0] != a[1][0] || a[0][n-1] != a[1][n-1]) return !printf("No");
    for(int i = 0; i < n - 1; i++) if(d[0][i] != d[1][i]) return !printf("No");
    return !printf("Yes");
}