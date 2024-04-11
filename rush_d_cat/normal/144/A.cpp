#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[102];
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    int val_max = *max_element(a + 1, a + 1 + n);
    int val_min = *min_element(a + 1, a + 1 + n);

    int pos_max = 0, pos_min = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] == val_max) {
            pos_max = i;
            break;
        }
    }
    for(int i = n; i >= 1; -- i) {
        if(a[i] == val_min) {
            pos_min = i;
            break;
        }
    } 
    int ans = (pos_min > pos_max) ? (n - pos_min + pos_max - 1) : (n - pos_min + pos_max - 2);
    cout << ans << endl;


}