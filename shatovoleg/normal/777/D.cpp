#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = unsigned long long;
using ld = long double;

void solve(string &a, string &b)
{
    if (a <= b)
        return;
    string a1 = a;
    a.clear();
    int i = 0;
    a.push_back(a1[i]);
    while (i < b.length() && a[i] <= b[i])
        a.push_back(a1[++i]);
    a.pop_back();
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (auto &x : arr)
        cin >> x;
    if (n == 1)
    {
        cout << arr.front() << endl;
        return 0;
    }
    for (int i = n - 1; i > 0; --i)
        solve(arr[i - 1], arr[i]);
    for (auto x : arr)
        cout << x << endl;
}