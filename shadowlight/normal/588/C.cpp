#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
const int inf = 1e6 + log(1e6);
int main() {
    int n, m = 0, k;
    scanf("%d", &n);
    vector <int> data(inf + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        data[k]++;
    }
    for (int i = 0; i < inf; i++) {
        data[i + 1] += data[i] / 2;
        m += data[i] % 2;
    }
    int s = data[inf];
    while (s != 0) {
        m += s % 2;
        s /= 2;
    }
    cout << m;

}