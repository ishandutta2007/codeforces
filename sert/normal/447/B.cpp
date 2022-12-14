#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int N = 1e6 + 34;

string s;
int a[N], n, mx = -34, sum;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> s;
    cin >> n;
    for (int i = 0; i < 26; mx = max(mx, a[i++]))
        cin >> a[i];
    for (int i = 0; i < s.length(); i++)
        sum += a[s[i] - 'a'] * (i + 1);
    for (int i = 0; i < n; i++)
        sum += mx * (i + s.length() + 1);
    cout << sum;
}