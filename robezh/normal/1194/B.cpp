#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)5e4 + 50, INF = (int)1e9;

int n, m;
string a[N];
int rsum[N], csum[N];

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i], a[i] = " " + a[i];
        fill(rsum, rsum + n + 1, 0);
        fill(csum, csum + m + 1, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i][j] == '.') rsum[i]++, csum[j]++;
            }
        }
        int mn = INF;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                mn = min(mn, rsum[i] + csum[j] - (a[i][j] == '.'));
            }
        }
        cout << mn << "\n";
    }
}