#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    int b = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        
        b += (a[i] % 2 != 0);
    }
    
    int b1 = b;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2) {
            if(b > b1 / 2)
            {
                if(a[i] > 0) {
                    a[i] = a[i] / 2;
                } else {
                    a[i] = (a[i] - 1) / 2;
                }
            }
            else {
                if(a[i] > 0)
                    a[i] = a[i] / 2 + 1;
                else 
                    a[i] = a[i] / 2;
            }
            b--;
        } else
            a[i] /= 2;
        cout << a[i] << endl;
    }
 }