#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k, kol[101104], ans[101104], gans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        kol[k]++;
    }
    for (int i = 0; i < 100003; i++) {
        ans[i + 4] = kol[i] * i + max(ans[i + 2], ans[i + 1]);
        gans = max(gans, ans[i + 4]);
    }
    cout << gans;
    return 0;
}