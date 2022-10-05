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
vector<int> knum(int x, int k) {
    vector<int> kk;
    while (x) {
        kk.push_back(x % k);
        x /= k;
    }
    return kk;
}
int numfrom(vector<int> kk, int k) {
    int res = 0;
    while (!kk.empty()) {
        res *= k;
        res += kk.back();
        kk.pop_back();
    }
    return res;
}
vector<int> add(vector<int> a, vector<int> b, int k, int minus = 0) {
    if (minus)
    for (int & i : b) {
        i *= -1;
        i += k;
        if (i >= k)
            i -= k;
    }
    if (a.size() < b.size())
        swap(a, b);
    for (int i = 0; i < b.size(); ++i) {
        a[i] += b[i];
        if (a[i] >= k)
            a[i] -= k;
    }
    return a;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> n1;
    for (int i = 0; i < n; ++i) {
        int num;
        if (i % 2) {
            num = numfrom(add(n1, knum(i, k), k, 1), k);
        } else {
            num = numfrom(add(n1, knum(i, k), k), k);
        }
        cout << num << endl;
        int x;
        n1 = add(knum(num, k), n1, k, 1);
        cin >> x;
        if (x)
            return;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}