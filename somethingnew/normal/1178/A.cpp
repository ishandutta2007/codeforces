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
    int a;
    cin >> a;
    int res = a;
    int sum = res;
    vector<int> num = {1};
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
        if (x * 2 <= a) {
            num.push_back(i + 1);
            res += x;
        }
    }
    if (res * 2 > sum) {
        cout << num.size() << '\n';
        for (int i = 0; i < num.size(); ++i) {
            cout << num[i] << ' ';
        }
    } else {
        cout << 0;
    }
}