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
    int n, k;
    cin >> n >> k;
    if(n < k){
        cout << k - n<<endl;
        return;
    }
    if(n % 2 == k % 2) {
        cout << 0<<endl;
        return;
    }
    cout << 1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}