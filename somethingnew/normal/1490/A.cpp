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
int valpair(int a, int b){
    if (a < b)
        swap(a, b);
    int res = 0, t = 2;
    while (a > b * t){
        res++;
        t *= 2;
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        res += valpair(a[i], a[i+1]);
    }
    cout << res << '\n';
}
dsgrekova krutaya() {
    int n;
    cin >> n;
    while (n--)
        solve();
}