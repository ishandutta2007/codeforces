#include <iostream>
#include <map>
using namespace std;
 
signed main() {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        int n, k, d;
        cin >> n >> k >> d;
        int mass[n];
        for (int i = 0; i < n; i++) {
            cin >> mass[i];
            mass[i]--;
        }
        map<int, int> arr;
        int kol = 0;
        for (int i = 0; i < d; i++) {
            if (arr[mass[i]] == 0) {
                kol++;
            }
            arr[mass[i]]++;
        }
        int minn = kol;
        for (int i = d; i < n; i++) {
            if (arr[mass[i - d]] == 1) {
                kol--;
            }
            arr[mass[i - d]]--;
            if (arr[mass[i]] == 0) {
                kol++;
            }
            arr[mass[i]]++;
            if (kol < minn) {
                minn = kol;
            }
        }
        cout << minn << "\n";
    }
    return 0;
}