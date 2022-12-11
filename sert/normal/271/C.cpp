#include <iostream>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    if (n < 3 * k){
        cout << "-1";
        return 0;
    }

    for(int i = 0; i < k; i++)
        cout << i + 1 << " " << i + 1 << " ";

    for(int i = k * 2; i < n; i++)
        cout << (i % k) + 1 << " ";

    return 0;
}