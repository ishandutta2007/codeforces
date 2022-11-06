#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;
using ll = unsigned long long;
using ld = long double;

int arr[][3] = {
    {0, 1, 2},
    {1, 0, 2},
    {1, 2, 0},
    {2, 1, 0},
    {2, 0, 1},
    {0, 2, 1}
};

int main()
{
    int n, k;
    cin >> n >> k;
    cout << arr[n % 6][k] << endl;
}