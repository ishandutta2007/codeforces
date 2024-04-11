//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> horivals(n), vertvals(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            cout << ((j & -j) * (j & -j) << 1) << ' ';
            horivals[j] = horivals[j-1] ^ ((j & -j) * (j & -j) << 1);
        }
        cout << endl;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (i & -i) * (i & -i) << ' ';
        }
        cout << endl;
        vertvals[i] = vertvals[i-1] ^ ((i & -i) * (i & -i));
    }
    
    int val = 0;
    for (int qq = 0; qq < k; ++qq) {
        int x;
        cin >> x;
        val ^= x;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (val == (vertvals[i] ^ horivals[j])) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                }
            }
        }
    }
}