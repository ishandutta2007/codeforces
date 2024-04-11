#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e7 + 13;
const int LOGN = 20;
const int A = 27;



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        if(a[i] > max(a[i - 1], a[i + 1]) || a[i] < min(a[i - 1], a[i + 1]))
            ans++;
    }

    cout << ans << endl;
}