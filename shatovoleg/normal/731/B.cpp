#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), v;
    for (auto &x : arr)
        cin >> x;
    bool is_possible = true, is_active = false;
    for (auto x : arr)
    {
        if (x & 1)
            is_active ^= true;
        if (!x && is_active)
            is_possible = false;
    }
    if (is_active)
        is_possible = false;
    if (!is_possible)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}