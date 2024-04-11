#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, i = 1;
    cin >> n >> k;
    int rem = 240 - k;
    for(i = 1; i <= n; i++) {
        if(rem >= 5*i)
            rem -= 5*i;
        else
            break;
    }
    cout << i - 1 << endl;
}