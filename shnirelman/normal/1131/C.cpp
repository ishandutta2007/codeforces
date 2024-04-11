#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    sort(a.rbegin(), a.rend());
    
    vector<int> b(n);
    int l = 0, r = n - 1;
    b[l] = a[0], b[r] = a[1];
    
    while(r > l + 1) {
        int i = l + (n - r) + 1;
        if(b[l] - a[i] < b[r] - a[i]) {
           b[r - 1] = a[i];
            r--;
           
        } else {
             b[l + 1] = a[i];
            l++;
            
        }
    }
    
    for(auto b1 : b)
        cout << b1 << ' ';
}