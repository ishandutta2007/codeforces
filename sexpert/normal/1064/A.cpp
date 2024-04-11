#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int m = max(a, max(b, c));
    int ans = 2*m - a - b - c + 1;
    cout << ((ans > 0) ? ans : 0) << endl;   
}