#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n * 2);
        for (auto& i : a)
            cin >> i;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " " << a[2*n-1-i] << " ";
        }
        cout << endl;
    }
    return 0;
}