#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int minh, maxh;
    if(k == 0) return !printf("0 0\n");

    if(k <= n - 1) minh = 1;
    else minh = 0;

    if(n >= (long long)k * 3) maxh = k * 2;
    else maxh = n - k;

    cout << minh << " " << maxh << endl;

}