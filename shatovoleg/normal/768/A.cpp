#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <complex>
#include <fstream>

using namespace std;
using pii = pair<int, int>;
using ll = unsigned long long;
using ld = long double;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for (auto x : arr)
        if (x > arr.front() && x < arr.back())
            ++cnt;
    cout << cnt << endl;
}