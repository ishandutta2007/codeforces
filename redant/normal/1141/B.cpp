#include <iostream>

using namespace std;

int a[200005];

int main(){
    int n;
    cin >> n;
    int x = -1, y = -1;
    int r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!a[i] && x == -1)
            x = i;
        if (!a[i]) {
            if (y != -1) {
                r = max(r, i - y - 1);
            }
            y = i;
        }
    }
    // cout << x << ", " << y << endl;
    r = max(r, x + n - 1 - y);
    cout << r << endl;
    return 0;
}