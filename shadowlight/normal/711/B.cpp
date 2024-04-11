#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector <long long> sum1(n, 0);
    vector <long long> sum2(n, 0);
    long long sum3 = 0, sum4 = 0;
    long long posx = 0, posy = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            long long x;
            cin >> x;
            if (x == 0) {
                posx = i;
                posy = j;
            }
            if (i == j) {
                sum3 += x;
            }
            if (i + j == n - 1) {
                sum4 += x;
            }
            sum1[i] += x;
            sum2[j] += x;
        }
    }
    //cout << sum3 << " " << sum4 << endl;
    long long good_sum = 0;
    good_sum = sum1[(posx + 1) % n];
    for (long long i = 0; i < n; i++) {
        if (posx != i && sum1[i] != good_sum) {
            cout << -1 << endl;
            return 0;
        }
        if (posy != i && sum2[i] != good_sum) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (posy != posx && good_sum != sum3) {
        cout << -1;
        return 0;
    }
    if (posy + posx != n - 1 && good_sum != sum4) {
        cout << -1;
        return 0;
    }
    if (sum2[posy] != sum1[posx]) {
        cout << -1;
        return 0;
    }
    if (posy == posx && sum1[posx] != sum3) {
        cout << -1;
        return 0;
    }
    if (posy + posx == n - 1 && sum1[posx] != sum4) {
        cout << -1;
        return 0;
    }
    if (sum1[posx] >= good_sum) {
        cout << -1;
        return 0;
    }
    cout << good_sum - sum1[posx];
}