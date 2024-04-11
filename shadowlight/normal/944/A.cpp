#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    a--, b--;
    while (a != b) {
        a /= 2;
        b /= 2;
        cnt++;
    }
    if (cnt == log2(n)) {
        cout << "Final!";
    } else {
        cout << cnt;
    }
    //cout << (cnt == log2(n) ? "Final!" : cnt);
}