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

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

//    if(k > 60) {
//        cout << "NO" << endl;
//        return;
//    }

//    int g = __gcd(a, b);
//    a /= g;
//    b /= g;

    int a1 = a, b1 = b;

    int cnt = 0;
    for(int i = 2; i * i <= max(a, b); i++) {
        while(a % i == 0) {
            cnt++;
            a /= i;
        }

        while(b % i == 0) {
            cnt++;
            b /= i;
        }
    }

    cnt += (a > 1) + (b > 1);

    cout << (cnt >= k && (k > 1 || (a1 % b1 == 0 || b1 % a1 == 0) && a1 != b1) ? "YES" : "NO") << endl;
}

/*
1
999999937 999999929 1
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin,tie(0);
    int t;

    cin >> t;

    while(t--)
        solve();
}