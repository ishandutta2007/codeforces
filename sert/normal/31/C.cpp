#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 5e3 + 34;

int n;
bool s[N], p[N];
pair <pair<int, int>, int> a[N];
vector <int> ans;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.first;
        cin >> a[i].first.second;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++)
        if (a[i].first.first < a[i - 1].first.second)
            break;
        else
            p[i] = true;
    for (int i = n - 2; i >= 0; i--)
        if (a[i].first.second > a[i + 1].first.first)
            break;
        else
            s[i] = true;
    p[0] = s[n - 1] = true;
    if (s[1]) ans.push_back(a[0].second);
    if (p[n - 2]) ans.push_back(a[n - 1].second);
    for (int i = 1; i < n - 1; i++)
        if (p[i - 1] && s[i + 1] && a[i - 1].first.second <= a[i + 1].first.first)
            ans.push_back(a[i].second);
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}