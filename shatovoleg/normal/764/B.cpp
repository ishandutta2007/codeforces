#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    int l = 0, r = n - 1;
    while (r > l)
    {
        if (l % 2 == 0)
            swap(arr[l], arr[r]);
        ++l;
        --r;
    }
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
}