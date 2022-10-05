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
    int n, k;
    cin >> n >> k;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        cout << (r ^ i) << endl;
        r = i;
        int x;
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