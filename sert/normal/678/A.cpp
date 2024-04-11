#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000 + 34;
typedef long double ld;

int n, k;

int main() {
    cin >> n >> k;
    n++;
    cout << k * ((n + k - 1) / k);
    return 0;
}