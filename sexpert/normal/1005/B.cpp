#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

int bs()
{
    int low = 0, high = n, mid;
    while(low != high)
    {
        mid = (low + high + 1)/2;
        if(a.substr(a.length() - mid) == b.substr(b.length() - mid)) low = mid;
        else high = mid - 1;
    }
    return low;
}

int main()
{
    cin >> a >> b;
    n = min(a.length(), b.length());
    int len = bs();
    cout << a.length() + b.length() - len - len;
}