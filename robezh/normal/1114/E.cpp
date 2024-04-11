#include <bits/stdc++.h>
using namespace std;

int n;

bool get(int x) {
    cout << "> " << x << "\n";
    fflush(stdout);

    int cnt;
    cin >> cnt;
    return cnt == 1;
}

int ask(int i) {
    cout << "? " << i << "\n";
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    int l = -1, r = (int)1e9, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(get(mid)) l = mid;
        else r = mid;
    }
    int gcd = 0;
    vector<int> nums;
    for(int i = 0; i < 30; i++) {
        nums.push_back(ask(rng() % n + 1));
    }
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 30; j++) gcd = __gcd(gcd, abs(nums[i] - nums[j]));
    }
    cout << "! " << r - gcd * (n - 1) << " " << gcd << "\n";
    fflush(stdout);
}