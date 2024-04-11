#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, res = 0;
    cin >> n;
    res += n/100;
    n%=100;
    res += n/20;
    n%=20;
    res += n/10;
    n%=10;
    res += n/5;
    n%=5;
    res += n;
    cout << res;
}