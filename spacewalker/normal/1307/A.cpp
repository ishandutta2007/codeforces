#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, d; scanf("%d %d", &n, &d);
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < arr[i]; ++k) {
                if (d < i) break;
                ++arr[0];
                d -= i;
            }
            if (d < i) break;
        }
        printf("%d\n", arr[0]);
        
    }
    return 0;
}