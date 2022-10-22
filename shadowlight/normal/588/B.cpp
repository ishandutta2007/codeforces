#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    long long n, m;
    cin >> n;
    m = n;
    for (long long i = 2; i <= sqrt(n); i++) {
        long long k = 0;
        while (m % i == 0) {
            m /= i;
            k++;
        }
        if (k != 0) m *= i;
    }
    cout << m;
}