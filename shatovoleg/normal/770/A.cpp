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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cout << char('a' + i % k);
    cout << endl;
}