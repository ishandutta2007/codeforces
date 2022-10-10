#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, a[1000], b[1000];
    string sa, sb;
    cin >> n >> sa >> sb;
    
    for (int i=0; i<n; i++) {
        a[i] = sa[i] - '0';
        b[i] = sb[i] - '0';
    }
    sort(a, a + n);
    sort(b, b + n);
    
    int ret1 = 0, ret2 = n, ptr1 = 0, ptr2 = 0;
    bool set1 = false, set2 = false;
    for (int i=0; i<n; i++) {
        while (ptr1 < n && b[ptr1] < a[i])
            ptr1++;
        if (ptr1 == n && !set1) {
            ret1 = n - i;
            set1 = true;
        }
        while (ptr2 < n && b[ptr2] <= a[i])
            ptr2++;
        if (ptr2 == n && !set2) {
            ret2 = i;
            set2 = true;
        }
        ptr1++;
        ptr2++;
    }
    
    cout << ret1 << endl << ret2 << endl;
    
    return 0;
}