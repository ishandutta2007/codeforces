#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"

#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & i : a)
        cin >> i;
    sort(all(a));
    vector<int> b;
    vector<int> c;
    int last = -1;
    for (auto i : a){
        if (last == i)
            c.push_back(i);
        else
            b.push_back(i);
        last = i;
    }
    for (auto i : b)
        cout << i << ' ';
    for (auto i : c)
        cout << i << ' ';
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}