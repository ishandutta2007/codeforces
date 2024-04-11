#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

int inf = (int)1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<bool> not_prime(1000000);
    vector<int> primes;
    vector<long long> div(1000000);
    for (long long i = 1; i < 1000000; i++) {
        if (!not_prime[i]) {
            primes.push_back(i + 1);
            for (long long x = 2 * (i + 1); x <= 1000000; x += (i + 1)) {
                not_prime[x - 1] = true;
                div[x - 1] = i + 1;
            }
        }
    }

    long long N;
    cin >> N;
    long long ans = N;
    for (int i = N - div[N - 1] + 1; i <= N; i++) {
        if (div[i - 1] > 0) ans = min(ans, i - div[i - 1] + 1);
    }

    cout << ans << endl;

    return 0;
}