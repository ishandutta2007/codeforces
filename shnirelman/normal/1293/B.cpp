#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;


void solve() {

}

int main() {
    //  ios_base::sync_with_stdio(0);
//  cin.tie(0);

    int n;
    cin >> n;

    ld ans = 0;
    for(int i = 0; i < n; i++) {
        ans += ld(1) / (n - i);
    }

    cout << setprecision(20) << fixed << ans;
}