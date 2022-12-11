#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int N = 1e6 + 34;

int n;
const int a[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    cout << a[n / 10] * a[n % 10];
}