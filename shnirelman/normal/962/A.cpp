#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int K = N * 30;
const int LOG = 30;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    int s1 = 0;
    for(int i = 0; i < n; i++) {
        s1 += a[i];
        if(s1 * 2 >= s) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}