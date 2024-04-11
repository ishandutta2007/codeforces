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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> heh(n+1);
    for (int i = 2; i <= n; i++) {
        cout << "? 1 " << i << endl;
        cin >> heh[i];
    }
    cout << "? 2 3" << endl;
    int kek;
    cin >> kek;
    heh[1] = heh[3] - kek;
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << heh[i] - heh[i-1] << ' ';
    }
    cout << endl;
}