#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
// #define int short
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> Ax;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Ax.insert(x);
        A.pb(x);
    }
    sort(A.begin(), A.end());
    int mini = 0, maxi = n;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (last > A[i]) {
            maxi--;
        } else {
            last = max(A[i] - 1, last + 1);
        }
    }
    A.clear();
    for (auto y : Ax) {
        A.pb(y);
    }
    sort(A.begin(), A.end());
    n = A.size();
    last = -228;
    for (int i = 0; i < n; i++) {
        if (last < A[i] - 1) {
            mini++;
            last = A[i] + 1;
        }
    }
    cout << mini << ' ' << maxi;


}