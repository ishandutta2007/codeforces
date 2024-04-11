#include <iostream>

using namespace std;

int main()
{
    int n, v;
    int sum;
    cin >> n >> v;
    if (v >= n)
        cout << n-1 << endl;
    else {
        sum = v;
        for (int i = 2; i <= n-v; i++)
            sum += i;
        cout << sum << endl;
    }
    return 0;
}