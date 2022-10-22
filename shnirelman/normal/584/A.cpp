#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int LOGN = 20;
const int A = 27;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, t;
    cin >> n >> t;

    if(n == 1) {
        cout << (t == 10 ? -1 : t);
        return 0;
    }

    cout << 1;
    for(int i = 0; i < n - 2; i++)
        cout << 0;

    int x = 1;
    for(int i = 0; i < n - 1; i++) {
        x = x * 10 % t;
    }

    cout << (t - x) % t;
}