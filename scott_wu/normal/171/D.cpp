#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    if (n <= 4)
    cout << n % 3 + 1 << "\n";
    else
    cout << 1 << "\n";
    return 0;
}