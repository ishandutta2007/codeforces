#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

const int N = 1e6 + 34;

int n;
vector <int> v;
pair <int, int> a[N];

void wr() {
    for (int i = 1; i <= n; i++)
        cout << a[i].second << " ";
    cout << "\n";
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
        if (a[i].first == a[i + 1].first)
            v.push_back(i);
    if (v.size() < 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    wr();
    swap(a[v[0]], a[v[0] + 1]);
    wr();
    swap(a[v[1]], a[v[1] + 1]);
    wr();
}