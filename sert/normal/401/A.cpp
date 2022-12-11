#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 2014;

void fail() {
    cout << "NO\n";
    exit(0);
}


ll n, k, sum, t;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t;
        sum += t;
    }

    cout << (abs(sum) + k - 1) / k;

    return 0;
}