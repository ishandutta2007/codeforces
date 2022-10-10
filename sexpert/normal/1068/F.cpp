#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k = (i + 3)/4, d = i % 4;
        if(d == 0)
            cout << 0 << " " << k << endl;
        if(d == 1)
            cout << k << " " << 0 << endl;
        if(d == 2)
            cout << 0 << " " << -k << endl;
        if(d == 3)
            cout << -k << " " << 0 << endl;
    }    
}