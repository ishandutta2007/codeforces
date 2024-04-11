#include <iostream>

using namespace std;

int main()
{
    long long sum = 0;
    int k, n, w;
    cin >> k >> n >> w;

    for (int i = 1; i <= w; i++) {
        sum += i * k;
    }

    sum = sum -= n;
    if (sum < 0)
        sum = 0;

    cout << sum << endl;
    return 0;
}