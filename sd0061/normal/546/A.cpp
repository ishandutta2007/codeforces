#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int main() {
    int n , k , w;
    cin >> k >> n >> w;
    int cost = k * w * (w + 1) / 2;
    cout << max(0 , cost - n) << endl;
    return 0;
}