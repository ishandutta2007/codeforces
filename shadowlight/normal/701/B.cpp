#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector <long long> used1(n + 1, 0), used2(n + 1, 0);
    long long cnt1 = 0, cnt2 = 0;
    long long sum = n * n;
    for (long long i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        if (!used1[x]) {
            used1[x] = 1;
            sum -= n - cnt2;
            cnt1++;
        }
        if (!used2[y]) {
            used2[y] = 1;
            sum -= n - cnt1;
            cnt2++;
        }
        cout << sum << " ";
    }
}