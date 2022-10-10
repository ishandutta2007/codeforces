#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt[2];
    cnt[1] = cnt[0] = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int m = *(max_element(a.begin(), a.end()));
    for(int i = 0; i < n; i++) {
        cnt[i%2] += (m - a[i] + 1)/2;
        cnt[(i + 1)%2] += (m - a[i])/2;
    }
    if(cnt[0] == cnt[1] || (cnt[0] == cnt[1] + 1 && n % 2 == 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}