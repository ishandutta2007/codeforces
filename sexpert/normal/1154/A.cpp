#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4];
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    int m = max({a[0], a[1], a[2], a[3]});
    for(int i = 0; i < 4; i++)
        if(m - a[i]) cout << m - a[i] << " ";
    cout << endl;
}