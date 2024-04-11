#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    long long d[n + 1];
    d[0] = 2;
    for (int i = 1; i < n; i++) {
        d[i] = 2 * d[i - 1];
    }
    long long k = 0;
    for (int i = 0; i < n; i++) k += d[i];
    cout << k << endl;
    //return 0;
}