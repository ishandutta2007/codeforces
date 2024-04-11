#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
void solve(){
    int a, b, c, d;
    cin>> a >> b >> c >> d;
    if(a > b * c){
        cout << "-1\n";
        return;
    }
    int p = a / b;
    p -= p % d;
    int k = p / d + 1;
    int ans = k * a;
    int m1 = p * k * b;
    int p1 = k * (k - 1) / 2 * b * d;
    //cout << p << ' ' << k << ' ' << m1 << ' ' << p1 << endl;
    cout << ans - m1 + p1 << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}