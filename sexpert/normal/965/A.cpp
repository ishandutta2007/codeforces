#include <bits/stdc++.h>
using namespace std;

int main()
{
    double k, n, s, p;
    cin >> k >> n >> s >> p;
    cout << int(ceil(k*ceil(n/s)/p));
}