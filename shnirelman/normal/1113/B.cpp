#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> c(102, 0);
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i]]++;
        s += a[i];
    }
    
    int ans = s;
    for(int i = 0; i < c.size(); i++)
        if(c[i] > 0)
            for(int j = 0; j < c.size(); j++)
                if(i != j && c[j] > 0) {
                    for(int k = 1; k <= i; k++)
                        if(i % k == 0) {
                            ans = min(ans, s - i - j + i / k + j * k);
                        }
                }
                
    cout << ans;
}