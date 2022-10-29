#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1005000;

vector< char > isPrime;

int
main()
{
    ios_base::sync_with_stdio(false);
    isPrime.assign(MAXN, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAXN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    int ind = -1;
    for (int i = 2; i <= n && ind == -1; ++i) {
        if (!isPrime[i] && !isPrime[n - i]) {
            ind = i;
        }
    }
    if (ind != -1) {
        cout << ind << " " << n - ind << '\n';
    }
    return 0;
}