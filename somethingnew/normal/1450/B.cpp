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
    vector<pair<int, int>> coord(n);
    for(auto &i : coord)
        cin >> i.first >> i.second;
    for (auto j : coord) {
        bool t = true;
        for (auto i : coord) {
            if(abs(j.first - i.first) + abs(j.second - i.second) > k) {
                t = false;
            }
        }
        if(t){
            cout << "1\n";
            return;
        }
    }
    cout << "-1\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}