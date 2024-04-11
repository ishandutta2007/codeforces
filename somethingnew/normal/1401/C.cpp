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
    int n;
    cin >> n;
    vector<int> lst(n);
    int mn = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
        mn = min(mn,lst[i]);
    }
    vector<int> lstcopy = lst;
    sort(lstcopy.begin(),lstcopy.end());
    for (int i = 0; i < n; ++i) {
        if(lst[i] != lstcopy[i] and lst[i] % mn != 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}