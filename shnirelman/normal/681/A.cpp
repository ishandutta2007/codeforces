#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const int LOGN = 20;



int main() {
    int n;
    cin >> n;

    bool ans = false;
    for(int i = 0; i < n; i++) {
        string s;
        int x, y;
        cin >> s >> x >> y;

        ans |= (x >= 2400 && y > x);
    }

    cout << (ans ? "YES" : "NO") << endl;
}