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
typedef long long ll;
using namespace std;
vector<int> table;
void solve(){
    int n;
    cin >> n;
    if (table[n]){
        cout << "Yes\n";
    } else{
        cout << "No\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    table.assign(1e6 + 10000, 0);
    table[0] = 1;
    for (int i = 0; i < 1e6; ++i) {
        if (table[i]){
            table[i + 2020] = 1;
            table[i + 2021] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        solve();
    }
}