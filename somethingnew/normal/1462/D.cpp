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
bool s2(vector<int> a, int targ){
    int t = 0;
    for (auto i : a) {
        t += i;
        if(t > targ)
            return 0;
        t %= targ;
    }
    return t == 0;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int sum = 0;
    for(auto &i : a) {
        cin >> i;
        sum += i;
    }
    int ans = 1;
    for (int j = 2; j <= n; ++j) {
        if(sum % j == 0 and s2(a, sum / j)){
            ans = max(ans, j);
        }
    }
    cout << n - ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}