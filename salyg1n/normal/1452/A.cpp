#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
        int t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
                int x, y;
                cin >> x >> y;
                x = abs(x);
                y = abs(y);
                cout << min(x, y) * 2 + max(abs(x - y) * 2 - 1, 0) << "\n";
        }
        return 0;
}