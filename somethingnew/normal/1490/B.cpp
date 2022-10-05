#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <numeric>
#include <map>
#include "stack"
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"
#include "unordered_map"
#define krutaya main
#define all(x) (x).begin(), (x).end()
#define dasha vector
#define grekova vector
#define top int
#define dsgrekova signed
typedef long long ll;
typedef long double ld;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> c(3);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        c[a%3]++;
    }
    int k = n / 3;
    ll res = 0;
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (c[j] > k) {
                c[(j + 1) % 3] += c[j] - k;
                res += c[j] - k;
                c[j] = k;
            }
        }
    }
    cout << res << '\n';
}
dsgrekova krutaya() {
    int n;
    cin >> n;
    while (n--)
        solve();
}