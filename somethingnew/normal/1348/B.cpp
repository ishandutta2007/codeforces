#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        vector<int> inn(n+1);
        vector<int> posl(k);
        int posn = 0;
        int num;
        for (int j = 0; j < n; ++j) {
            cin >> num;
            inn[num] += 1;
            if (inn[num] == 1){
                if (posn < k){
                    posl[posn] = num;
                    posn += 1;
                }else posn += 1;
            }
        }
        if (k < posn){
            cout << -1 << '\n';
        } else{
            cout << n * k << '\n';
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < posn; ++l) {
                    cout << posl[l] << ' ';
                }
                for (int m = 0; m < k- posn; ++m) {
                    cout << "1 ";
                }
            }
        cout << '\n';
        }

    }
}