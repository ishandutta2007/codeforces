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
void solve(){
    ll n;
    cin >> n;
    if (n == 1){
        cout << "No\n";
        return;
    }
    while (n % 2 == 0){
        n /= 2;
    }
    if (n == 1){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}