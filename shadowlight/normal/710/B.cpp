#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const long long INF = 1e9;


int main() {
    long long n;
    cin >> n;
    vector <long long> data(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    long long min_rast = 0;
    for (long long i = 0; i < n; i++) {
        min_rast += data[i] - data[0];
    }
    //cout << min_rast << endl;
    long long prev = min_rast, pos = 0;
    for (long long i = 1; i < n; i++) {
        long long now = prev + (data[i] - data[i - 1]) * (2 * i - n);
        if (now < min_rast) {
            min_rast = now;
            pos = i;
        }
        prev = now;
        //cout << now << endl;
    }
    cout << data[pos];
}