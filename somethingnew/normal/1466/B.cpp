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
    map<int, int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x+1]++;
    }
    set<int> b;
    int prev = -100;
    for (auto i : a) {
        if (i.second == 1) {
            if (prev != i.first - 1)
                b.insert(i.first - 1);
            else {
                b.insert(i.first);
                prev = i.first;
            }
        }
        if (i.second > 1) {
            b.insert(i.first - 1);
            b.insert(i.first);
            prev = i.first;
        }
    }
    cout << b.size() << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}