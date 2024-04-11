#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int main() {
    int n , K;
    cin >> n >> K;
    if (K == 1 || n <= 3) {
        puts("-1");
    } else if (K >= n) {
        puts("-1");
    } else if (n == 4) {
        // 2 < K < n
        if (K == 3) {
            puts("3\n1 2\n2 3\n3 4");
        } else {
            puts("-1");
        }
    } else { // n > 4
        if (K == 3) {
            vector<pair<int , int> > E;
            E.push_back({1 , 2});
            E.push_back({2 , 3});
            E.push_back({3 , 4});
            for (int i = 2 ; i <= 3 ; ++ i) {
                for (int j = 5 ; j <= n ; ++ j) {
                    E.push_back({i , j});
                }
            }
            printf("%d\n" , E.size());
            for (auto it : E) {
                printf("%d %d\n" , it.first , it.second);
            }
        } else if (K == 2) {
            printf("%d\n" , n - 1);
            for (int i = 1 ; i < n ; ++ i) {
                printf("%d %d\n" , i , i + 1);
            }
        } else {
            puts("-1");
        }
    }
}