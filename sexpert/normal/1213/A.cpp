#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<int> cnt(2);
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        cnt[x % 2]++;
    }
    cout << min(cnt[0], cnt[1]) << '\n';
}