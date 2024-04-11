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
int mindel(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return i;
    }
    return x;
}
bool ch(int x) {
    int mm = mindel(x);
    while (x % mm == 0) x/=mm;
    return x == 1;
}
void solve(){
    long long n;
    cin >> n;
    long long res = 0;
    long long mod = (int)1e9 + 7;
    int i = 2;
    while (n) {
       // cerr << i << endl;
        int t = mindel(i);
        long long nshtr = n;
        n /= t;
        res += (nshtr - n) % mod * i % mod;
        res %= mod;
        while (!ch(++i));
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}