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
    vector<int> a(2);
    for (int i = 0; i < n * 2; ++i) {
        int x;
        cin >> x;
        a[x % 2]++;
    }
    if (a[0] == a[1])
        cout << "YES\n";
    else
        cout << "No\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}