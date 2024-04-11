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
void pr(vector<int> a) {
    for (int i = 0; i + 1 < a.size(); ++i) {
        cout << a[i] << '.';
    }
    cout << a.back() << '\n';
}
void solve(){
    int n;
    cin >> n;
    vector<int> elems = {1};
    cout << 1 << '\n';
    int q;
    cin >> q;
    for (int i = 1; i < n; ++i) {
        int k;
        cin >> k;
        if (k == 1) {
            elems.push_back(1);
        } else {
            while (elems.back() != k - 1)
                elems.pop_back();
            elems.back()++;
        }
        pr(elems);
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