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
    if(n > 45){
        cout << "-1\n";
        return;
    }
    int ncopy = n;
    int sz = 0;
    vector<int> a(10, 0);
    for (int i = 9; i > 0; --i) {
        if(ncopy >= i) {
            ncopy -= i;
            a[i] = 1;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if(a[i])
            cout << i;
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}