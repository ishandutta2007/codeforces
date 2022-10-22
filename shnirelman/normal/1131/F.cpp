#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n, -1), sz(n, 1), lst(n);
    for(int i = 0; i < n; i++) {
        a[i] = i;
        lst[i] = i;
    }
        
    for(int i = 0; i < n - 1; i++) {
        int a1, b1;
        cin >> a1 >> b1;
        a1--;
        b1--;
        
        a1 = a[a1];
        b1 = a[b1];
        //cout << a1 << ' ' << b1 << endl;
        if(sz[a1] < sz[b1]) {
            swap(a1, b1);
            
            
        }
        
        sz[a1] += sz[b1];
        
        b[lst[a1]] = b1;
        lst[a1] = lst[b1];
        
        for(int j = b1; j != -1; ) {
            a[j] = a1;
            j = b[j];
            if(j == -1)
                break;
        }
    }
    
    for(int i = a[0]; i != -1; ) {
        cout << i + 1 << ' ';
        i = b[i];
        if(i == -1)
            break;
    }
        
}