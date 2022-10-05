#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include "fstream"
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"
#include "bitset"
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
signed main() {
    bitset<200005> nums;
    nums[0] = 1;
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &i : a){
        cin >> i;
        nums |= nums << i;
        sum += i;
    }
    if (sum % 2 == 0 and nums[sum / 2]) {
        cout << 1 << endl;
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = a[j];
                if (t % (2 << i)) {
                    cout << j + 1;
                    return 0;
                }
            }
        }
    } else {
        cout << 0;
    }
}