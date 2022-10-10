#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = 1;
    while(k*k <= n)
        k++;
    k--;
    if(n == k * k)
        cout << 2*k << endl;
    else if(n <= k*(k + 1))
        cout << 2*k + 1 << endl;
    else
        cout << 2*k + 2 << endl;
}