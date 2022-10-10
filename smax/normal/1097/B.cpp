#include <bits/stdc++.h>
using namespace std;

int n, a[15];

bool bash(int i, int sum) {
    if (i == n)
        return sum % 360 == 0;
    return bash(i+1, sum+a[i]) || bash(i+1,sum-a[i]);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    if (bash(0, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}