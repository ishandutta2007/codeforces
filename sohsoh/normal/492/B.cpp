#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long n, l;
    cin >> n >> l;

    vector<long long> v;

    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        v.push_back(k);
    }

    sort(v.begin(), v.end());

    long double d1 = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        long  double d_tmp = (v[i + 1] - v[i]) / 2.0;

        d1 = max(d1, d_tmp);
    }

    long  double d2 = l - v[v.size() - 1];
    long  double d3 = v[0];

    d1 = max(max(d2, d3), d1);

    cout << fixed << d1 << endl;
}