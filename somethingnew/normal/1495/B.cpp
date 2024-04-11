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
void maax(int &a, int b, int &c) {
    if (a == b)
        c++;
    else if (a < b) {
        a = b;
        c = 1;
    }
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> up(n), down(n);
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i-1])
            up[i] = up[i-1] + 1;
    }
    for (int j = n - 2; j >= 0; --j) {
        if (a[j] > a[j + 1])
            down[j] = down[j + 1] + 1;
    }
    //for (int i = 0; i < n; ++i) {
    //    cout << up[i] << ' '<< down[i] << endl;
    //}
    int mx = -1;
    int cnt = 0;
    int mx2 = -1;
    int cnt2 = 0;
    for (int k = 0; k < n; ++k) {
        maax(mx2, up[k],cnt2);
        maax(mx2, down[k], cnt2);
        if (down[k] == up[k]) {
            if (up[k] > mx) {
                mx = up[k];
                cnt = 0;
            }
            if (up[k] == mx)
                cnt++;
        }
    }

    if (mx2 > mx or mx == 0){
        cout << "0\n";
        return;
    }
    if (cnt2 > 2) {
        cout << "0\n";
        return;
    }
    if (mx % 2 == 0) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    n = 1;//cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}