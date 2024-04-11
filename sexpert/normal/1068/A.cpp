#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k, l;
    cin >> n >> m >> k >> l;
    long long minGift = k + l;
    long long cand = minGift / m;
    cand += (minGift % m) ? 1 : 0;
    cout << ((cand * m <= n) ? cand : -1) << endl;
}

// k + l <= mx <= n
// x >= (k + l)/m;