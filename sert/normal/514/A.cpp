#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;
    int arr[20], t = 0;
    while (n) {
        arr[t] = n % 10;
        arr[t] = min(arr[t], 9 - arr[t]);
        n /= 10;
        t++;
    }
    if (arr[t - 1] == 0)
        arr[t - 1] = 9;
    for (int i = t - 1; i >= 0; i--)
        cout << arr[i];

    return 0;
}