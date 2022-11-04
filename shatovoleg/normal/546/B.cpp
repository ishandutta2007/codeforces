#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for (int i = 1; i < n; ++i)
        if (arr[i] <= arr[i - 1])
        {
            cnt += arr[i - 1] - arr[i] + 1;
            arr[i] = arr[i - 1] + 1;
        }
    cout << cnt << endl;
}