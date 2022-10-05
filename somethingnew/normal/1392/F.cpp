#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long k;
        cin >> k;
        sum += k;
    }
    vector<long long> prefres(n, 0);
    for (long long j = 1; j < n; ++j) {
        sum-=j;
        prefres[n-j]++;
    }
    long long k = sum / n;
    prefres[0] += k;
    long long q = sum % n;
    prefres[0]++;
    prefres[q]--;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += prefres[i];
        cout << res << ' ';
    }
}