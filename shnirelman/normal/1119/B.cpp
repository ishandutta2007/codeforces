#include <bits/stdc++.h>

using namespace std;

bool is(int h, vector<int> a1, int n) {
    vector<int> a;
    for(int i = 0; i < n; i++)
        a.push_back(a1[i]);
        
    
        
    sort(a.rbegin(), a.rend());
    //for(int i = 0; i < n; i++)
    //    cout << a[i] << ' ';
    
    for(int i = 0; i < n; i++) {
        if(a[i] > h)
            return false;
            
        h -= a[i];  
        
        if(i < n - 1)
            i++;
            
        
        
    }
    
    return true;
}

int main() {
    int n, h;
    cin >> n >> h;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
        
    
    for(int i = n; i > 0; i--) {
        if(is(h, a, i)) {
            cout << i;
            return 0;
        }
    }
        
}