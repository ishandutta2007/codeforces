#include <bits/stdc++.h>
using namespace std;

int k,n,s,p;

int main() {
    cin >> k >> n >> s >> p;
    int res = ((n + s - 1) / s * k + p - 1) / p;

    cout << res;

    return 0;
}