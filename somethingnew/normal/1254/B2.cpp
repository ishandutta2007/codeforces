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
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
vector<long long> prm(long long x) {
    vector<long long> res;
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            res.push_back(i);
        while (x % i == 0)
            x /= i;
    }
    if (x != 1)
        res.push_back(x);
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (auto &i : a){
        cin >> i;
        sum += i;
    }
    if (sum == 1) {
        cout << "-1\n";
        return;
    }
    long long ans = 1e18;
    for (auto x : prm(sum)) {
        long long rt = 0;
        long long an = 0;
        int p = 0;
        int ind = 0;
        for (auto i : a) {
            ind++;
            i %= x;
            if (rt * 2 >= x) {
                int t = min(x - rt, i);
                an += t * (ind - p);
                rt += t;
                if (rt == x) {
                    rt = i - t;
                    if (rt * 2 >= x)
                        p = ind;
                }
            } else {
                an += rt;
                rt += i;
                rt %= x;
                if (rt * 2 >= x)
                    p = ind;
            }
        }
        ans = min(ans, an);
    }
    cout << ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}