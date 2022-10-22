#include <iostream>

using namespace std;

int main()
{
    long n, k;
    cin >> n >> k;

    int remain = k - n % k;
    cout << n + remain << endl;
    return 0;
}