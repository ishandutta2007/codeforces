#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005;

int n, k;

bool check(int x) {
    return 1LL * x * x + 1LL * 3 * x <= 2LL * n + 2LL * k;
}



int main() {
    cin >> n >> k;
    int l = -1, r = (int)1e6;
    while(l + 1 < r) {
        int mid = (l + r ) /2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << n - l << endl;
}