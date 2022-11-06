#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n += 2;
    bool *arr = new bool[n];
    for (int i = 0; i < n; ++i)
        arr[i] = true;
    for (int i = 2; i < n; ++i)
        if (arr[i])
            for (int j = 2 * i; j < n; j += i)
                arr[j] = false;
    if (n <= 4)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    for (int i = 2; i < n; ++i)
        cout << (2 - arr[i]) << " ";
    cout << endl;
}