#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        res = max(res, min(a - 1, 1000000 - a));
    }
    cout << res;
    return 0;
}