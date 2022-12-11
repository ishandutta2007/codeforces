#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int N = 1e6 + 34;

int n, lst = -1;
pair <int, int> a[N];

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        lst = (a[i].second >= lst ? a[i].second : a[i].first);
    cout << lst;
}