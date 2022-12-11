#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

pair <int, int> a[100000];
vector <int> ans;
int n, m, cur;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        a[i].second = i + 1;
        cin >> a[i].first;
    }
    a[n] = make_pair(m + 34, -34);
    sort(a, a + n);
    while (m >= a[cur].first) {
        ans.push_back(a[cur].second);
        m -= a[cur++].first;
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}