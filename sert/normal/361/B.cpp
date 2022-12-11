#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 134;

int n, k;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n >> k;
    if (n == k) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < n - k - 1; i++)
        printf("%d ", i + 2);
    cout << "1";
    for (int i = n - k; i < n; i++)
        printf(" %d", i + 1);

    return 0;
}