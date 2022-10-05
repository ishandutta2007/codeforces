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
#define int long long
using namespace std;
int andik(int a, int b) {
    cout << "and " << a << ' ' << b << endl;
    int res;
    cin >> res;
    return res;
}
int orik(int a, int b) {
    cout << "or " << a << ' ' << b << endl;
    int res;
    cin >> res;
    return res;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> orr(n), andd(n);
    int andorr, orandd;
    for (int i = 1; i < n; ++i) {
        orr[i] = orik(1, i + 1);
        andd[i] = andik(1, i + 1);
        if (i == 1) {
            andorr = orr[i];
            orandd = andd[i];
        } else {
            andorr &= orr[i];
            orandd |= andd[i];
        }
    }
    int num2 = orik(2, 3);
    int a0 = orandd;
    for (int i = 0; i < 31; ++i) {
        if (((1 << i) & num2) == 0 and andorr & (1 << i)) {
            a0 |= andorr & (1 << i);
        }
    }
    vector<int> a(n);
    a[0] = a0;
    for (int i = 1; i < n; ++i) {
        a[i] = orr[i] ^ andd[i] ^ a[0];
    }
    sort(all(a));
    cout << "finish " << a[k - 1];
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    //cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}