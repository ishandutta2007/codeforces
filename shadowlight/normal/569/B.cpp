#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int> num(n + 1), used(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        if (num[i] <= n) used[num[i]]++;
    }
    int z = 1;
    for (int i = 1; i <= n; i++) {
        if (num[i] <= n && used[num[i]] > 1) {
            for (int j = z; j <= n; j++) {
                if (used[j] == 0) {
                    used[num[i]]--;
                    num[i] = j;
                    used[j] = 1;
                    z = j + 1;
                    break;
                }
            }
        } else if (num[i] > n) {
           for (int j = z; j <= n; j++) {
                if (used[j] == 0) {
                    num[i] = j;
                    used[j] = 1;
                    z = j + 1;
                    break;
                }
            }
        }
    }
     for (int i = 1; i <= n; i++) {
        cout << num[i] << " ";
    }
}