#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n , a[N][5] , b[N][5];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < 5 ; ++ j) {
            scanf("%d" , &a[i][j]);
        }
    }
    if (n >= 233) {
        puts("0");
        return 0;
    }
    vector<int> res;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < n ; ++ j) {
            for (int k = 0 ; k < 5 ; ++ k) {
                b[j][k] = a[j][k] - a[i][k];
            }
        }
        bool flag = 0;
        for (int j = 0 ; j < n ; ++ j) {
            for (int k = j + 1 ; k < n ; ++ k) {
                if (j == i || k == i) continue;
                int sum = 0 , s0 = 0 , s1 = 0;
                for (int l = 0 ; l < 5 ; ++ l) {
                    sum += b[j][l] * b[k][l];
                }
                if (sum > 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) {
            res.emplace_back(i + 1);
        }
    }
    cout << res.size() << endl;
    for (auto &x : res) {
        cout << x << ' ';
    } cout << endl;
}