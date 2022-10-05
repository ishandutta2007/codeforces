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
void solve(){
    int n;
    cin >> n;
    vector<int> dw(n);
    int res = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        if (a > b)
            swap(a, b);
        dw[a]++;
        if (dw[a] == 1)
            res++;
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int t;
        cin >> t;
        if (t == 3) {
            cout << n - res << '\n';
        }
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            a--;b--;
            if (a > b)
                swap(a, b);
            dw[a]++;
            if (dw[a] == 1)
                res++;
        }
        if (t == 2) {
            int a, b;
            cin >> a >> b;
            a--;b--;
            if (a > b)
                swap(a, b);
            dw[a]--;
            if (dw[a] == 0)
                res--;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    //cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}