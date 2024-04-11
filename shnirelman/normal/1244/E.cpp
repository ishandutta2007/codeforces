#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    /*for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }*/
    
    int l = 0, r = n - 1;
      
    int cur = 0;
    while(k > 0 && cur < 7 * n) {
        cur++;
        while(l < n - 1 && a[l] == a[l + 1]) {
            l++;
        }
            
        while(r > 0 && a[r] == a[r - 1]) {
            r--; 
        }
            
        if(l >= r)// || (cur > 1 && !fl))
            break;
            
        if(l + 1 < n - r) {
            long long d = min(a[l + 1] - a[l], k / (l + 1));
            //cout << "edsab " << d << endl;
            a[l] += d;
            if(l != 0)
                a[0] += d;
            k -= (l + 1) * d;
        } else {
            long long d = min(k / (n - r), a[r] - a[r - 1]);
            //cout << d << endl;
            a[r] -= d;
            if(r != n - 1) 
                a[n - 1] -= d;
            k -= d * (n - r);
        }
        
        //cout << l << ' ' << r << ' ' << a[l] << ' ' << a[r] << endl;
    }
    
    cout << a[n - 1] - a[0];
}