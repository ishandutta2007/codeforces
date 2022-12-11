#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 5003;
int n, k;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    cout << (k % 2 ? k / 2 : (n - k) / 2) + 1;


    return 0;
}