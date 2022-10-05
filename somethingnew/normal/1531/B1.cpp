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

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, int> cnt;
    map<pair<int, int>, int> cntelems;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (a != b)
            cnt[b]++;
        cnt[a]++;
        cntelems[{a, b}]++;
    }
    long long res = 0;
    for (auto [elem, cn] : cntelems) {
        res += cn * (cn - 1ll);
        if (elem.second != elem.first) {
            res += cn * (cnt[elem.second] - cn);
        }
        res += cn * (cnt[elem.first] - cn);
    }
    cout << res / 2;
}