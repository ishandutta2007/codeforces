#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    vector <int> cap(n + 1, 0);
    vector <int> data1;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        cap[a] = 1;
        data1.push_back(data[a - 1]);
    }
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        if (cap[i + 1]) {
            sum1 += data[i];
        } else {
            sum2 += data[i];
        }
    }
    long long all_sum = sum1 * sum2;
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += data1[i] * (sum1 - data1[i]);
    }
    for (int i = 0; i < n; i++) {
        if (!cap[i + 1] && !cap[(i + 1) % n + 1]) {
            all_sum += data[i] * data[(i + 1) % n];
        }
    }
    cout << all_sum + sum / 2;
}