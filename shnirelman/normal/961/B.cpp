#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 200 + 13;
const int K = N * 30;
const int LOG = 30;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] == 1) {
            s += a[i];
            a[i] = 0;
        }
    }


    vector<int> p(n + 1, 0);
    for(int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];

    int mx = 0;
    for(int i = k; i <= n; i++) {
        mx = max(mx, p[i] - p[i - k]);
    }

    cout << s + mx << endl;
}