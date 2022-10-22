#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int cur = 0 - n;
    int curn = 0;
    while (cur + curn * 5 + 20 < k) {
        curn++;
        cur += curn * 5 + 15;
        curn += 4;
    }
    while (cur != k) {
        curn++;
        cur += (curn+1);
    }
    cout << n - curn << endl;
    return 0;
}